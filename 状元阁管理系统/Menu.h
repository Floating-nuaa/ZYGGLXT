#ifndef MENU_H_
#define MENU_H_

class Menu 

//这是一个菜单的抽象类

{
public:
	
	Menu() {};
	virtual void display()=0;
	virtual ~Menu() {}

};

#endif 