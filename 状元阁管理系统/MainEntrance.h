/**************************************************************
				MainEntrance
		主入口类 从Main 函数中调用 
		理论上没有数据成员 
***************************************************************/
#ifndef  MAINENTRANCE_H_
#define  MAINENTRANCE_H_
#include "LoginMenu.h"
#include "stdafx.h"
#include "PremaryMenu.h"
#include "LoginMenu.h"
class MainEntrance 
{

public :
	
	MainEntrance();
	~MainEntrance();

	void ShowPre_Login();

};

#endif // ! MAINENTRANCE_H_
