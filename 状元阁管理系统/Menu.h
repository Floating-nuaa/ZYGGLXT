#ifndef MENU_H_
#define MENU_H_
#include <iostream>
using namespace std;
class Menu 

//这是一个菜单的抽象类

{
public:
	Menu() {};
	virtual void display()=0;
	virtual ~Menu() { cout << "调用了Menu的析构函数" << endl; }
};

#endif 
