#include "AddTEAMenu.h"
#include <string.h>


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
	char cname[30], csex = 'F', cphone[20], cQQ[20];
	memset(cname, '\0', 30);

	memset(cphone, '\0', 20);
	memset(cQQ, '\0', 20);
	cin >> name >> sex >> phone >> QQ;
	cout << endl;
	if (display2()) 
	{
		cout << "请输入更改后薪水： ";
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
	Purpose sub;
	sub = catchPurpose();
	Teacher TEA(cname, csex, cphone, cQQ, sub,salary);
	
	teacher = TEA;
}

bool AddTEAMenu:: display2() 

	//询问是否变更薪水

{
	cout << "是否变更默认薪水？Y or N :  " ;
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

Purpose AddTEAMenu::catchPurpose()

{
	vector<string> list;
	int a = 1;
	cout << "请输入教学科目数量 :  " ;
	cin >> a;
	cout << endl;
	string ttt;
	cout << "请输入分别输入课程名称，中间用空格隔开 (如:语文 数学)" << endl;

	for (int i = 1; i <= a; i++)
	{
		cout << "请输入第 " << i << " 个科目 :  ";
		cin >> ttt;
		list.push_back(ttt);
	}
	if (a == 0)
	{
		ttt = "无科目";
		list.push_back(ttt);

	}
	Purpose pur(list);
	return pur;

}