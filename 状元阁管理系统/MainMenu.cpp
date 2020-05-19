#include "MainMenu.h"
#include <iostream>
using namespace std;

MainMenu::MainMenu() {}

void MainMenu::display() 

{
	
	system("cls");
	cout << "************************************************************************" << endl<<endl<<endl;
	cout << "\t\t状元阁管理系统" << endl << endl << endl;
	cout << "\t1. 学员报名  2. 学员订课  3. 学员缴费  " << endl<<endl;
	cout << "\t4. 查询课表  5. 修改课表  6. 生成课表  " << endl << endl;
	cout << "\t7. 教师风采  8. 管理登录  9. 内部通道  " << endl << endl;
	cout << endl;
	cout << "************************************************************************" << endl<<endl;

}

int MainMenu::getCommend()
{
	int commender=0;
	do 
	{
		cout << "请输入您要使用功能的编号 :  ";
		cin >> commender;
	
	} while (commender < 0 || commender>9);
	
	return commender;
}



