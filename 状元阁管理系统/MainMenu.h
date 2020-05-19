#ifndef MAINMENU_H_
#define MAINMENU_H_
#include "Menu.h"

class MainMenu :public Menu

	//这是主菜单类，是进入的功能选择

{

public:

	MainMenu();
	void display();
	~MainMenu() {  };
	int getCommend();


};

#endif // !MAINMENU_H_

