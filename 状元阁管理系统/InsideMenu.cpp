#include "InsideMenu.h"
#include <iostream>
using namespace std;
InsideMenu::InsideMenu() 
{

}
InsideMenu::~InsideMenu() {

}
void InsideMenu::display()
{
	system("cls");
	cout << "*************************************************************************" << endl << endl << endl;
	cout << "\t\t状元阁管理系统内部功能" << endl << endl << endl;
	cout << "\t1.  注册管理员    2. 查询教师信息    3. 查询学生信息  " << endl << endl;
	cout << "\t4.  添加新教师    5. 修改教师信息    6. 修改学生信息  " << endl << endl;
	cout << "\t7.  查询工资表    8. 教学事故记录    9. 查询课程单价  " << endl << endl;
	cout << "\t10. 店内流水账    11.查询系统记录    12.管理者的通道  " << endl << endl;
	cout << endl;
	cout << "************************************************************************" << endl << endl;
}

int InsideMenu::getCommend()
{
	int commender = 0;
	do 
	{
		cout << "请输入您要使用功能的编号 :  ";
		cin >> commender;
	} while (commender < 0 || commender > 12);
	return commender;
}


