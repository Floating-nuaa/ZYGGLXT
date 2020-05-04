#ifndef  PREMENU_H_
#define PREMENU_H_

#include "Menu.h"

#include <iostream>
using namespace std;

class PremaryMenu :public Menu
{
public:
	PremaryMenu(){}
	void display();
	~PremaryMenu() { cout << "调用了PremaryMenu的析构函数！" << endl; };
};
#endif // ! PREMENU_H_

