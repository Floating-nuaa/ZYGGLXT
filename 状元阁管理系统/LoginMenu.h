#ifndef  LOGINMENU_H_
#define LOGINMENU_H_
#include "Menu.h"
#include <string>
using namespace std;
class LoginMenu:public Menu 
{

protected:

	bool checkBigPassword(string s);				//检测经营者邀请码

	bool checkPassword(string input);				//检测个人登录密码
	
	bool saveAccount(string name, string password); //保存当前注册账户

	string login_one();								//接收密钥

	void register_one();							//进行注册的第一部分

	void register_two();							//进行注册的第二部分

public :

	void display();									//外部展示性接口
	bool checkInDisplay();							//外边登录权限性接口
};

#endif // ! LOGIN_H_
