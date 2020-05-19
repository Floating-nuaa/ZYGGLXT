#ifndef  MANAGER_H_
#define MANAGER_H_
#include "People.h"
#include "stdafx.h"
class Manager :public People

{

protected :

	char SSH[30];		//密钥，一些关于账目的管理需要密钥验证身份
						//需要使用时转成string进行比较
public :


	Manager(char* name, char sex, char* phone, char*);
	Manager();
	~Manager();
	Manager(const Manager&);
	//重载一下赋值号
	
	Manager operator =(const Manager& obj);
	
	//更改个人管理密钥
	void display();

	bool setSSH();

	string getSSH();	//返回密钥,只能通过友元Handler调用

	bool checkSSH(string ssh);

};

#endif // ! MANAGER_H_

