#ifndef  LOGINMENU_H_
#define LOGINMENU_H_
#include "Menu.h"
#include <string>
using namespace std;
class LoginMenu:public Menu 
{

protected:

	bool checkBigPassword(string s);

	bool checkPassword(string input);
	
	bool saveAccount(string name, string password);

	string login_one();//接收密钥

	void register_one();//检测Bigboss授权码

	void register_two();//进行注册

public :

	void display();

};

#endif // ! LOGIN_H_
