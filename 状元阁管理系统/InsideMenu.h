#ifndef  INSIDEMENU_H_
#define INSIDEMENU_H_
#include "Menu.h"
/**********************************************************************************************
		这是内部功能菜单，进入内部渠道后进行选择
***********************************************************************************************/
class InsideMenu :public Menu 


{
public:
	InsideMenu();
	~InsideMenu();
	void display();
	int getCommend();
};

#endif // ! INSIDEMENU_H_
