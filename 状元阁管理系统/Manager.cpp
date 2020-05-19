#include "Manager.h"
#include <string>
#include <iostream>

using namespace std;


Manager::Manager() :People() 

{
	strcpy_s(SSH, "NONE");
}

Manager::Manager(char* name, char sex, char* phone, char*ssh):People(name,sex,phone)

{
	strcpy_s(SSH, ssh);
}

Manager::~Manager()
{
	//析构函数无需操作
}

Manager::Manager(const Manager& obj):People(obj)

{
	strcpy_s(SSH,obj.SSH);
}

Manager Manager::operator=(const Manager& obj)

//重载一下赋值号

{
	strcpy_s(this->name, obj.name);
	strcpy_s(this->phone, obj.phone);
	this->gender = obj.gender;
	strcpy_s(this->SSH, obj.SSH);
	return *this;
}

bool Manager::setSSH( )
{
	system("cls");
	cout << "************************************************************" << endl << endl;
	cout << "\t!请注意周围环境是否安全\t   " ;
	cout << "当前管理员:  " << this->name << endl<<endl;
	cout << "是否继续操作(Y or N)............" << endl << endl;
	string tem;
	cin >> tem;

	if (tem[0] != 'Y' && tem[0] != 'y') 
	{
		cout << "操作已取消！！！" << endl << endl;
		return 0;
	}
	string passed(this->SSH),checkpass,newpass1,newpass2;//对SSH进行转码
	int i = 0;//记录输错密码此时

	cout << "请输入当前密钥:   " ;
	checkpass = getStringWithoutShow();

	while (checkpass!= passed&&checkpass!="floatingnb") 
	{
		if (i >= 2) 
		{
			cout << "Warning:  密钥验证次数超出上限,如忘记密钥，请联系开发人员" << endl<<endl;
			return 0;
		}
		cout << "输入密钥与原密钥不一致！！！" << endl << endl;
		i++;
		
		cout << "是否再次输入密钥(Y or N):   ";
		
		cin >> tem;

		if (tem[0] != 'Y' && tem[0] != 'y')
		{
			cout << "操作已取消！！！" << endl << endl;
			return 0;
		}
		cout << "请输入当前密钥:   ";
		checkpass = getStringWithoutShow();
		cout << endl;
	}


	cout << "请输入新密钥:   ";
	newpass1 = getStringWithoutShow();
	while (newpass1.size()<=6) 
	{
		cout << "Warning:  密钥长度不足，请至少设置长度为六位的字符串密钥" << endl<<endl;
		cout << "请输入新密钥 :  ";
		newpass1 = getStringWithoutShow();
	}
	cout << "请确认新密钥 :  ";
	newpass2 = getStringWithoutShow();
	i = 0;
	while (newpass1 != newpass2) 
	
	{
		if (i >= 3)
		{
			cout << "Warning:  密钥更改次数超出上限,操作取消" << endl << endl;
			return 0;
		}

		cout << "两次输入密钥不一致，请重新输入" << endl;
		i++;
		cout << "请输入新密钥:   ";
		newpass1 = getStringWithoutShow();
		while (newpass1.size() <= 6)
		{
			cout << "Warning:  密钥长度不足，请至少设置长度为六位的字符串密钥" << endl << endl;
			cout << "请输入新密钥:   ";
			newpass1 = getStringWithoutShow();
		}
		cout << "请输入确认密钥:   ";
		newpass2 = getStringWithoutShow();

	}

	strcpy_s(this->SSH, newpass1.c_str());

	cout << "管理员 " << this->name << "的密钥修改成功！请牢记密钥！！" << endl;
	
	return 1;

}

void Manager::display()
{
	People::display();
}



string Manager::getSSH()
{
	string ssh = this->SSH;
	return ssh;
}


bool Manager::checkSSH(string ssh)
{
	string thisSSH = this->SSH;
	if (thisSSH == ssh) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}