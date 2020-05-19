#include "RegisterManagerMenu.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

RegisterManagerMenu::RegisterManagerMenu():Man()

{
	//构造函数，无需操作
}

RegisterManagerMenu:: ~RegisterManagerMenu() 

{
	//析构函数，无需操作
}

void RegisterManagerMenu::display() 
{

	system("cls");

	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t管理员信息注册" << endl;
	cout << "请注意 : 当前注册信息会作为您使用本系统的唯一识别码" << endl;
	cout << "请注意 : 请您仔细填写，否则可能会造成无法预料的后果" << endl;
	//cout << "谢谢您的理解和对本管理系统的支持，祝您工作愉快，幸福安康！" << endl;

	if (!checkToContinue()) 
	{//询问是否继续
		operationCancled();
		return;
	}
	
	if(!checkQuality())
	{//检测授权码
		operationCancled();
		return;
	}
	
	char name[30], phone[20], gender, ssh[30];
	cout << "友情提示 : 下面进行管理员信息填写，请注意周围环境!!!" << endl;
	cout << "请输入您的姓名   :  ";
	cin >> name;
	cout << "请输入您的性别   :  ";
	gender = checkGender();
	cout << "请输入联系电话   :  ";
	cin >> phone;
	cout << "接下来要输入的是您的私人管理密钥,在使用内部功能时会进行审查" << endl;
	cout << "友情提示 : 请您仔细填写!!!" << endl;
	strcpy_s(ssh, getSSHFromScreen().c_str());
	Manager manager(name, gender, phone, ssh);
	this->Man = manager;
	string tem = name;
	if (!saveThisMan(tem)) 
	{
		cout << "很遗憾 管理员信息保存失败，请检测文件保存路径" << endl;
		cout << "无法解决请联系开发人员Floating ！！" << endl;
		return;
	}
	cout << "创建管理员信息成功，请您牢记您的密码!!! " << endl;
	return;
}

bool RegisterManagerMenu::checkQuality() 
//检测管理员权限
{
	int cnt=0;
	string BBP;
	try 
	{
		while (1)
		{
			if (cnt >= 3)
			{
				cout << "校验BigBoss授权码次数超出上限，操作取消" << endl;
				return 0;
			}
			
			cout << "请输入BigBoss授权码 :  ";
			
			BBP = getStringWithoutShow();//从屏幕获取密码

			if (checkBigPassword(BBP)) 
			{
				return 1;
			}
			cnt++;
		}
	
	}
	catch (int) 
	{
		cout << "Warning  BigBoss授权码异常 ，请检查文件路径是否存在 ！" << endl;
		return 0;
	}
	return 0;
}

string RegisterManagerMenu::getSSHFromScreen()
{
	string newpass1, newpass2;
	cout << "请输入您的密钥:   ";
	newpass1 = getStringWithoutShow();
	while (newpass1.size() <= 6)
	{
		cout << "Warning:  密钥长度不足，请至少设置长度为六位的字符串密钥" << endl << endl;
		cout << "请输入您的密钥:   ";
		newpass1 = getStringWithoutShow();
	}
	cout << "请确认您的密钥:   ";
	newpass2 = getStringWithoutShow();
	int	i = 0;
	while (newpass1 != newpass2)

	{
		if (i >= 5)
		{
			cout << "Warning:  操作次数超出上限，已经启用默认密钥" << endl ;
			cout << "如需修改请先登录，然后进行修改" << endl;
			return "dongge666";
		}

		cout << "两次输入密钥不一致，请重新输入" << endl;
		i++;
		cout << "请输入您的密钥:   ";
		newpass1 = getStringWithoutShow();
		while (newpass1.size() <= 6)
		{
			cout << "Warning:  密钥长度不足，请至少设置长度为六位的字符串密钥" << endl << endl;
			cout << "请输入您的密钥:   ";
			newpass1 = getStringWithoutShow();
		}
		cout << "请确认您的密钥:   ";
		newpass2 = getStringWithoutShow();

	}
	return newpass1;
}

bool RegisterManagerMenu::saveThisMan(string name) 
{
	PerInfo PIT("TotalManager");
	string addName = "MagInfo//" + name;
	
	PerInfo PIP(addName);
	ofstream TotFile, PrFile;
	
	TotFile.open(PIT.getCompleteAddress(), ios::out | ios::app | ios::binary);
	PrFile.open(PIP.getCompleteAddress(),ios::out|ios::binary);
	
	if (!TotFile) 
	{
		cout << " TotalManager 信息表打开失败！" << endl;
		cout << "请检测路径" << PIT.getCompleteAddress() << "是否存在！";
		return 0;
	}
	if (!PrFile)
	{
		cout << " Manager 信息表创建失败！" << endl;
		cout << "请检测路径" << PIP.getCompleteAddress() << "是否存在！";
		return 0;
	}
	
	TotFile.write((char*)&this->Man, sizeof(this->Man));
	PrFile.write((char*)&this->Man, sizeof(this->Man));
	
	TotFile.close();
	PrFile.close();
	return 1;
}


Manager RegisterManagerMenu::getManager() 
{
	return this->Man;
}
