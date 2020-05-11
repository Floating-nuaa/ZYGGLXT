#ifndef RUNNINGMENU_H_
#define RUNNINGMENU_H_
#include "stdafx.h"
#include "Menu.h"
#include "Manager.h"

class RunningMenu : public Menu
/****************************************************
		流水账菜单类
	会收集信息，生成一个 RunningRecord ,并保存在问价中				
	最后修改时间 2020/5/11
******************************************************/
{
protected:

	Manager operatorManager;
	bool display2();

public:
	
	RunningMenu(Manager&);
	~RunningMenu();
	RunningMenu(const RunningMenu&);

	RunningMenu operator= (const RunningMenu&);
	virtual void display();

};

#endif // !RUNNINGMENU_H_







