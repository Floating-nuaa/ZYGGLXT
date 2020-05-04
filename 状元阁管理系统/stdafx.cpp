#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"
<<<<<<< HEAD
=======
#include "BaseFile.h"
>>>>>>> dev
using namespace std;


bool checkBigPassword(string s) 

//第一行是BigBoss授权码
//#号结尾，后有endl
{
	
	ifstream password;
	
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;
	
	password.open(file, ios::in);
	
	if (!password) 
	{
		cout << "password.txt can't be opened!" << endl;
		exit(0);
	}
	
	char  pass[20];
	string a;
	
	password.getline(pass, 20,'#');
	
	password.close();
	
	a = pass;
	
	if (s == a) {
		return 1;
	}
	return 0;
}

<<<<<<< HEAD


=======
>>>>>>> dev
bool saveAccount(string name, string password) 

//保存账户说明：前方结尾是回车
//密码在前，账户名在后，中间 “#” 隔开
//最后有换行符

{
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;
	
	char na[20], pa[30];
	
	strcpy_s(na, name.c_str());
	strcpy_s(pa, password.c_str());
	
	ofstream f(file, ios::out|ios::app);
	
	if(!f)
	{
		cout << file << " can't be opened !" << endl;
		system("pause");
		return 0;
	}
	
	f << pa;
	
	f.put('#');
	f << na;

	f.put(10);
	
	f.close();
	
	return 1;
}

<<<<<<< HEAD


=======
>>>>>>> dev
bool checkPassword(string input) 

//从密码文件中提取数据，与输入数据进行核验

{
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;
	
	ifstream password;
	password.open(file, ios::in);
	char pa[30];
	string str;

	//判断读取密码,保证所有路径都有返回值，
	//用异常处理增强健壮性
	
		bool temp = 0;
		while (!password.eof()) 
		{
			password.getline(pa, 49, '#');
			str = pa;
			
			if (input == str) 
			{
				temp = 1;
				password.close();
				return 1;
			}

			char cc = password.get();
			while (!password.eof()&&cc != 10) 
			{
				cc = password.get();
			}

		}
		//如果没有查找到，抛出0
		if (!temp) {
			password.close();
			throw 0;
			return 0;
		}
		
}

<<<<<<< HEAD

bool saveStudentData(Student obj) 
{
	return 1;
=======
bool saveStudentData(Student obj) 
{
	return 1;
}

bool checkSaveAddress(string saveAddress) 

//功能函数说明：
//这是检测更改文件储存路径是否合法的函数
//合法返回1 否则返回零
//会创建一个可以删除的测试文件
{

	if (saveAddress[0] != 'E' && saveAddress[0] != 'C' && saveAddress[0] != 'D') 
	{
		return 0;
	}
	if (saveAddress[1] != ':') 
	{
		return 0;
	}
	if (saveAddress[2] != '\\')
	{
		return 0;
	}
	//以上的检测很不完善，但几乎能避免因为格式不正确，引起的在相对路径下建立
	//同名文件的问题
	ofstream checkin;
	
	string  fileAddress = saveAddress;
	
	string fileName = "检测路径.txt";
	
	string file = fileAddress + fileName;
	
	checkin.open(file, ios::out);

	if (!checkin) 
	
	{
		return 0; 
	}
	checkin << "路径检测成功！！！！" << endl;
	checkin << "(本文件可以移除)" << endl;
	return 1;

	checkin.close();

>>>>>>> dev
}