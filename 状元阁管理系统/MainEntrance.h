/**************************************************************
				MainEntrance
		主入口类 从Main 函数中调用 
		理论上没有数据成员 
***************************************************************/
#ifndef  MAINENTRANCE_H_
#define  MAINENTRANCE_H_
#include "stdafx.h"
#include "PremaryMenu.h"
#include "LoginMenu.h"
#include "FeasibleCmd.h"
#include "MainMenu.h"
#include "Handler.h"
#include "OperateTable.h"
#include "InsideMenu.h"
#include "RegisterManagerMenu.h"
#include "SalaryTable.h"


class MainEntrance 
{

private:
	int commender;//命令代码寄存器
	Handler Hander;

public :
	
	MainEntrance();
	~MainEntrance();
	

	void ShowThe_First();				//展示先导界面
	void ShowPre_Login();				//登录界面
	int  ShowMain_Menu();				//主菜单
	bool DealFirt_Comd(int Comd);		//处理主菜单的命令
	int  ShowInde_Menu();				//显示内部菜单
	bool DealSecn_Comd(int Comd);		//处理内部菜单的命令
	int  ShowMang_Menu();				//管理员特有功能，集成一体化

};

#endif // ! MAINENTRANCE_H_
