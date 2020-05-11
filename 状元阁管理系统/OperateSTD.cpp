#include "OperateSTD.h"
#include "PeoNum.h"
#include "AddSTDMenu.h"
#include "PerInfo.h"

#include <fstream>

OperateSTD::OperateSTD() {}

OperateSTD::~OperateSTD(){}

void OperateSTD::getInfoFromScreen()

//把保护变量里的STD 填入信息

{
	AddSTDMenu  ASM;

	ASM.display();
	stud =  ASM.getStudent();
	string name(stud.getName());

	STDInfo SI(name);
	saveAddress = SI;
}

bool OperateSTD::saveThisFile() 
{
	setStdsID(this->stud);
	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);

	if (!file) 
	
	{
		cout << "学生个人信息文件打开失败，请检查路径是否正确！" << endl;
		return 0;
	}
	
	file.write((char*)&stud, sizeof(stud));
	file.close();
	PerInfo PI;//创建人信息保存地址
	
	ofstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary |ios::app);
	
	if (!perFile) 
	{
		cout << "人员信息总文件打开失败，请检查路径是否正确！" << endl;
		
		return 0;

	}
	perFile.write((char*)&stud, sizeof(stud));
	perFile.close();
	
	return 1;
}

bool OperateSTD::readPreFile( ) 
	
	//读出信息，储存在私有域中

{
	string thisName="test";
	cout << "\t请输入要查询学生的姓名:  ";
	cin >> thisName;
	cout << endl;
	saveAddress.setName(thisName);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "学生信息文件打开失败，请检查路径和姓名是否正确！" << endl;
		return 0;
	}

	file.read((char*)&stud, sizeof(stud));
	file.close();
	//student.display();
	return 1;

}

Student OperateSTD::getStudent() 

{
	return this->stud;
}

void OperateSTD::setStdsID(People& obj) 

{
	//更改ID
	PeoNum PN;

	obj.ID = PN.returnNum();

}

bool OperateSTD::readPreFile(string STDname)
{
	saveAddress.setName(STDname);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "学生信息文件打开失败，请检查路径和姓名是否正确！" << endl;
		return 0;
	}
	file.read((char*)&stud, sizeof(stud));
	
	file.close();
	return 1;
}