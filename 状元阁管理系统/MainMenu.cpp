#include "MainMenu.h"
#include <iostream>
using namespace std;

MainMenu::MainMenu() {}

void MainMenu::display() 

{
	
	system("cls");
	cout << "************************************************************" << endl<<endl<<endl;
	cout << "\t\t状元阁管理系统" << endl << endl << endl;
	cout << "\t1.学员报名 2.学员缴费 3.查询课表 " << endl<<endl;
	cout << "\t4.修改课表 5.教师简介 6.内部通道 " << endl << endl;
	cout << "************************************************************" << endl<<endl;
	system("pause");


}