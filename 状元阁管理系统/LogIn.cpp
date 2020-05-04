#include <iostream>
#include <string>
#include <fstream>
#include "stdafx.h"
using namespace std;

string login_one();//接收密钥
void register_one();//检测Bigboss授权码
void register_two();//进行注册
void login_main();//登录到主界面

string welcome()
//首界面函数,欢迎界面

{
	system("cls");
	cout << "--------------------------------------------------------" << "|"<<endl;
	cout << endl <<endl << endl<< endl << endl;
	cout << endl << endl << endl ;
	cout <<"\t"<< "欢迎使用状元阁信息管理系统" << endl;
	cout << endl  << endl << endl<<endl<<endl; 
	cout <<"\t\t\t\t"<< "请您先进行登陆！"<<endl<<endl;
	cout << endl << endl << endl << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	
	system("pause");
	string s1= login_one();
	
	if (s1 == "register") 
	{
		register_one();
		exit(0);
	}
	
	//如果返回的密钥是register，则进行注册
	try 
	{
		checkPassword(s1);
	}
	catch (int ) 
	{
		cout <<"\t\t无此用户信息！请您重新输入！"<<endl;
		system("pause");
		welcome();
	}
	login_main();
	cout << "\t\t感谢您使用本系统！" << endl;
	return s1;

}
string login_one() 
//登录函数，实现的功能有链接注册函数和进入主功能页面
{
	system("cls");
	cout << "--------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "首次登陆请输入指令register！" << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t\t请输入密钥：";
	string s;
	cin >> s;
	cout << endl << endl << endl << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	system("pause");
	return s;
}
void register_one() {

		system("cls");
		cout << "--------------------------------------------------------" << endl;
		cout << endl << endl << endl << endl << endl;
		cout << "请输入BigBoss的授权码：";
		string s;
		cin >> s;
		bool tem = 0;
		
		cout << endl << endl << endl << endl << endl;
		cout << "--------------------------------------------------------" << endl;
		
		if (checkBigPassword(s))

		{
			register_two();
		}
		else

		{
			cout << "Sorry，授权码非法，请您与BigBoss联系！" << endl;
		}
		return;
}
void register_two() 
{
	system("cls");
	cout << "--------------------------------------------------------" << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "请输入注册用户名: ";
	string name,password;
	cin >> name;
	cout << "请输入您的密钥: ";
	cin >> password;
	try {
		if (saveAccount(name, password)) 
		{
			system("cls");
			cout << "创建账户成功，请重新登录！" << endl;
		}
		else 
		{
			throw 1;
		}
	}
	catch (int) {
		system("cls");
		cout << "创建账户失败,程序异常，请与开发者联系！" << endl;
		system("pause");
	}
	
}

<<<<<<< HEAD


=======
>>>>>>> dev
void login_main()

//首界面功能选择函数

{
	system("cls");
	cout << endl << endl;
	cout << "**************************************************************************************" << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "\t\t1.增加学生\t2.增加老师\t3.学生缴费\t4.获取帮助" << endl;
	cout << endl << endl << endl << endl << endl;
	cout <<"**************************************************************************************" << endl;

	system("pause");

}