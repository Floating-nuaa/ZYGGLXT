#include "OperateSTD.h"
#include "Student.h"
#include "STDInfo.h"
#include <fstream>
#include "AddSTDMenu.h"

using namespace std;


OperateSTD::OperateSTD() {}

OperateSTD::~OperateSTD(){}

void OperateSTD::getInfoFromScreen()

//把保护变量里的STD 填入信息

{
	AddSTDMenu  ASM;

	ASM.display();
	student =  ASM.getStudent();
	string name(student.getName());

	STDInfo SI(name);
	saveAddress = SI;
}

bool OperateSTD::saveThisFile() 
{
	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);
	
	if (!file) 
	
	{
		cout << "学生信息文件打开失败，请检查路径是否正确！" << endl;
		return 0;
	}
	
	file.write((char*)&student, sizeof(student));
	file.close();
	
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

	file.read((char*)&student, sizeof(student));
	file.close();
	//student.display();
	return 1;

}

Student OperateSTD::getStudent() 

{
	return this->student;
}