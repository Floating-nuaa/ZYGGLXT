#include "BaseFile.h"
#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>


using namespace std;
string BaseFile :: REGISTERADDRESS= "E:\\VisualStudio\\Data\\";

void BaseFile::RESETADDRESS(string RERE) 

{
	REGISTERADDRESS = RERE; 
}


BaseFile::BaseFile() :saveAddress(REGISTERADDRESS)

{
	uniqueAddress = "Test\\";
	fileName = "test.txt";
	completeFile = saveAddress + uniqueAddress + fileName;
}

BaseFile::BaseFile(const BaseFile& obj) 
{
	uniqueAddress = obj.saveAddress;//功能文件夹
	fileName = obj.fileName;//文件的名
	completeFile = obj.completeFile;//完整文件路径
}

BaseFile BaseFile::operator=(const BaseFile& obj) 
{
	uniqueAddress = obj.saveAddress;//功能文件夹
	fileName = obj.fileName;//文件的名
	completeFile = obj.completeFile;//完整文件路径
	return *this;
}

BaseFile::BaseFile(string UA, string FA):saveAddress(REGISTERADDRESS)

//第一个参数是功能描述，第二个参数是文件名称

{
	uniqueAddress = UA;
	fileName = FA;
	completeFile = saveAddress + uniqueAddress + fileName;
}


string BaseFile::getCompleteAddress()

{
	return completeFile;
}

string BaseFile::getSaveAddress()

{
	return saveAddress;
}

string BaseFile::getfileName() 

{
	return fileName; 
}


void BaseFile::setFileName(string FA) 
{
	fileName = FA; 
	completeFile = saveAddress + uniqueAddress + fileName;
}


void BaseFile::changeSaveAddress() 
{

	cout << "请输入BigBoss授权码！" << endl;
	string pass;
	pass = getStringWithoutShow();
	
	try 
	{

		try
		{
			if (!checkBigPassword(pass))
			{
				throw pass;
			}
		}
		catch (string goal)
		{
			cout << "您刚刚输入的是 " << goal << endl;
			cout << "授权码错误，请联系BigBoss或者Floating！" << endl;
			throw goal;
		}

		string newSavaAddress;
		
		try
		{
			cout << "当前的储存路径是 " << this->getSaveAddress() << endl;
			
			cout << "请输入更改后的路径(与现有路径相同的格式，文件夹之间用\\隔开) ";
			
			cout<< endl << "$ ";

			cin >> newSavaAddress;

			bool temp;

			temp = checkSaveAddress(newSavaAddress);

			if (!temp)
			
			{
				throw newSavaAddress;
			}

			cout << "新的储存路径是  " << newSavaAddress << endl;
			
			cout << "是否继续 Y or N ？" << endl;
			
			cin.ignore();
			char  cc=getchar() ;
			
			if (toupper(cc) == 'Y')

			{
				RESETADDRESS(newSavaAddress);
				cout << "储存路径修改成功！" << endl;
			}

			else
			
			{
				throw -1;
			}
		}

		catch (string goal)
		{
			cout << "您刚刚输入的是 " << goal << endl;
			cout << "输出的储存路径非法，请重新检查路径！" << endl;
		}

		catch (int N)
		{

			cout << "操作代码-1：  操作取消！" << endl;
		}
		
	}

	catch (string ggg) 
	{
		cout << "操作取消!!!！" << endl;
	}
	
}

void BaseFile::display() 
{
	cout << completeFile << endl;
}

