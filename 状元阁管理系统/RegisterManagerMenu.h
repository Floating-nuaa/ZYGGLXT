/**********************************************************************
			RegisterManager 类
		注册管理员的类，不同于其他的添加或者操作菜单
		这个操作是要通过内部渠道进入，获得Boss授权进行注册
		这个manager信息非常重要，是以后收银权限，添加课程等权限的必要凭证


***********************************************************************/
#ifndef REGISTERMANAGERMENU_H_
#define REGISTERMANAGERMENU_H_
#include "Menu.h"
#include "Manager.h"
#include "PerInfo.h"
#include "stdafx.h"
class RegisterManagerMenu:public Menu 
{
protected:
	
	Manager Man;
	bool checkQuality();
	string getSSHFromScreen();
	bool saveThisMan(string name);

public:
	
	RegisterManagerMenu();
	~RegisterManagerMenu();
	virtual void display();  //填入成员的属性

	Manager getManager();

};


#endif // !REGISTERMANAGER_H_

