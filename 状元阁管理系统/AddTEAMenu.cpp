#include "AddTEAMenu.h"



AddTEAMenu::AddTEAMenu(){}

AddTEAMenu::~AddTEAMenu(){}

AddTEAMenu::AddTEAMenu(const AddTEAMenu& obj) 
//拷贝构造
{
	this->teacher = obj.teacher;
}

void AddTEAMenu::display() 

//char* name, char sex, char* phone, char* QQ, int salary)
//People(name, sex, phone)

{

	system("CLS");
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t添加教师信息" << endl << endl;
	cout << "\t\t请按照以下方式进行教师信息输入" << endl << endl;
	cout << "  A.  1.姓名 2.性别（F or M）3.电话号码 4.QQ " << endl;
	catchAndAnylasis();
}

void AddTEAMenu::catchAndAnylasis() 

//捕获并且给对象进行赋值

{
	string name, sex, phone, QQ;
	int salary = 60;
	char cname[15], csex = 'F', cphone[20], cQQ[20];
	cin >> name >> sex >> phone >> QQ;
	if (display2()) 
	{
		cout << "\t请输入更改后薪水： ";
		cin >> salary;
	}
	//转换成字符数组
	strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);
	strcpy_s(cQQ, QQ.c_str());
	strcpy_s(cphone, phone.c_str());

	if (sex[0] == 'M'||sex[0]=='m')
	{
		csex = 'M';
	}

	if (sex[0] == 'F'||sex[0]=='f')
	{
		csex = 'F';
	}

	Teacher TEA(cname, csex, cphone, cQQ, salary);
	
	teacher = TEA;
}

bool AddTEAMenu:: display2() 

	//询问是否变更薪水

{
	cout << "\t是否变更默认薪水？Y or N :  " ;
	string ans;
	cin >> ans;
	if (ans[0] == 'Y' || ans[0] == 'y') 
	{
		return 1;
	}
	return 0;
}

Teacher AddTEAMenu::getTeacher() 

{
	return this->teacher;
}