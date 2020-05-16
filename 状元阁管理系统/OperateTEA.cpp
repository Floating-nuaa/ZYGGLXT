#include "OperateTEA.h"
#include "PeoNum.h"
#include "PerInfo.h"

OperateTEA::OperateTEA(){}

OperateTEA::~OperateTEA(){}

OperateTEA::OperateTEA(const OperateTEA& obj) 
{
	this->teacher = obj.teacher;
}

void OperateTEA::getInfoFromScreen()

//把保护变量里的STD 填入信息
{

	AddTEAMenu  ATM;

	ATM.display();
	teacher = ATM.getTeacher();
	string name(teacher.getName());

	TEAInfo TI(name);
	
	saveAddress = TI;
}

bool OperateTEA::saveThisFile()

//保存文件
{
	setTeasID(this->teacher);

	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);

	if (!file)

	{
		cout << "教师信息文件打开失败，请检查路径是否正确！" << endl;
		return 0;
	}

	file.write((char*)&teacher, sizeof(teacher));
	file.close();

	PerInfo PI("TotalTeacher");//创建人信息保存地址

	ofstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::app|ios::out);

	if (!perFile)
	{
		cout << "教师信息总文件打开失败，请检查路径是否正确！" << endl;

		return 0;

	}
	file.write((char*)&teacher, sizeof(teacher));
	perFile.close();
	cout << "Success  教师信息保存成功!" << endl;
	return 1;
}

bool OperateTEA::readPreFile()

//从文件中读取文件信息

{
	string thisName = "test";
	cout << "\t请输入要查询教师的姓名:  ";
	cin >> thisName;
	cout << endl;

	saveAddress.setName(thisName);
	
	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "教师信息文件打开失败，请检查路径和姓名是否正确！" << endl;
		return 0;
	}

	file.read((char*)&teacher, sizeof(teacher));
	file.close();
	return 1;

}



Teacher OperateTEA::getTeacher() 

{

	return this->teacher;

}

void OperateTEA::setTeasID(People& obj)

{
	//更改ID
	PeoNum PN;

	obj.ID = PN.returnNum();

}


bool OperateTEA::readPreFile(string name)

//从文件中读取文件信息

{
	string thisName = name ;
	saveAddress.setName(thisName);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "教师信息文件打开失败，请检查路径和姓名是否正确！" << endl;
		return 0;
	}

	file.read((char*)&teacher, sizeof(teacher));
	file.close();
	return 1;

}


