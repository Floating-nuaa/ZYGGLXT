#include <iostream>
#include <string>
#include <fstream>
#include "stdafx.h"
#include "LoginMenu.h"
using namespace std;


void LoginMenu:: display()
//首界面函数,欢迎界面

{
	system("cls");
	cout << "********************************************************" << "" << endl;
	cout << endl << endl << endl ;
	cout <<"\t"<< "欢迎使用状元阁信息管理系统" << endl;
	cout << endl;
	cout <<"\t"<< "请 您 先 进 行 登 陆 ！"<<endl<<endl;
	cout << endl << endl << endl << endl << endl;
	cout << "********************************************************" << endl;
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
		display();
	}
	return;

}



bool LoginMenu::checkInDisplay()
{

	system("cls");
	cout << "********************************************************" << "" << endl;
	cout << endl << endl << endl;
	cout << "\t" << "欢迎使用状元阁信息管理系统" << endl;
	cout << endl;
	cout << "\t" << "请 您 先 进 行 登 陆 ！" << endl << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "********************************************************" << endl;
	system("pause");

	string s1 = login_one();

	if (s1 == "register") //如果返回的密钥是register，则进行注册
	{
		register_one();
		exit(0);
	}
	
	try
	{
		if (checkPassword(s1)) 
		{
			return 1;				//查找成功，返回1
		}
	}
	catch (int)
	{
		/*cout << "Warning 无此用户信息！请您重新输入！" << endl;
		system("pause");
		display();*/
		return false;
	}
	return false;

}



string LoginMenu::login_one()
//登录函数，实现的功能有链接注册函数和进入主功能页面
{
	system("cls");
	cout << "*********************************************************" << endl;

	cout << endl;
	cout << "\t如果这是您首次登录,请输入指令register！" << endl<<endl;
	cout << "\t请输入您的个人登录码 :  ";
	string s;
	do 
	{
	s = getStringWithoutShow();
	} while (s == ""||s==" "|| s=="\n");
	cout << endl << endl << endl << endl << endl;
	cout << "********************************************************" << endl;
	return s;
}



void LoginMenu::register_one() {

		system("cls");
		cout << "*****************************************************************" << endl;
		cout << endl ;
		cout << "\t您即将设置个人登录密码,设置后您需要重新进入本系统 " << endl<<endl;
		cout << "请输入BigBoss的授权码 :  ";
		string s;
		s = getStringWithoutShow();
		bool tem = 0;
		cout << endl << endl << endl << endl << endl;
		cout << "*****************************************************************" << endl;
		
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



void LoginMenu::register_two()
{
	system("cls");
	cout << "*****************************************************************" << endl;
	cout << endl;
	cout << "\t请输入注册用户名 :  ";
	string name,password;
	cin >> name;
	cout << "请输入您的密钥:   ";
	password = getStringWithoutShow();
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



bool LoginMenu::saveAccount(string name, string password)

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

	ofstream f(file, ios::out | ios::app);

	if (!f)
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



bool LoginMenu::checkPassword(string input)

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
		while (!password.eof() && cc != 10)
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
	return 0;
}



bool LoginMenu::checkBigPassword(string s)

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

	password.getline(pass, 20, '#');

	password.close();

	a = pass;

	if (s == a) {
		return 1;
	}
	return 0;
}

