#ifndef RUNNINGMENU_H_
#define RUNNINGMENU_H_
#include "stdafx.h"
#include "Menu.h"
#include "Manager.h"
#include "RunningRecord.h"
#include "RecordInfo.h"

/****************************************************
		流水账菜单类
	会收集信息，生成一个 RunningRecord ,并保存在RunningRecord文件中
	这个class封装性非常高，对外部只提供唯一接口 display
	没有无参构造，必须传入参数Manager

	最后修改时间 2020/5/11
******************************************************/


class RunningMenu : public Menu
{
protected:

	Manager operatorManager;
	bool display2();

	bool saveRunRecord(RunningRecord );

public:
	
	RunningMenu(Manager&);
	~RunningMenu();
	RunningMenu(const RunningMenu&);

	RunningMenu operator= (const RunningMenu&);
	virtual void display();

};

#endif // !RUNNINGMENU_H_


