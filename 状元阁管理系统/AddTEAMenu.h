#ifndef  ADDTEAMENU_H_
#define ADDTEAMENU_H_
#include "Menu.h"
#include "AddSTDMenu.h"
#include "Teacher.h"


class AddTEAMenu : public Menu 

	//增加教师菜单类，输入教师信息
	
{
protected:

	Teacher teacher;

	void catchAndAnylasis();
	bool display2();
	Purpose catchPurpose();

public:
	
	AddTEAMenu();
	~AddTEAMenu();

	AddTEAMenu(const AddTEAMenu&);

	void display();//重载Menu类的display
	
	Teacher getTeacher();

};

#endif // ! ADDTEAMENU_H_

