/************************************************************************
                
				AddTABMenu  
		主要功能是从屏幕端创建一个课表
		高度封装，对外部只提供display 接口和返回Table的接口
		主要是OperateTable模块进行调用
		有一点要注意是生成的Table不能先进行在屏幕显示再进行保存
		当然可用创建副本的方法进行


		最后修改时间 2020/5/15  作者  Flaoting

**************************************************************************/


#ifndef ADDTABMENU_H_
#define ADDTABMENU_H_
#include "Menu.h"
#include "Table.h"
#include "OperateSTD.h"
#include "stdafx.h"
class AddTABMenu :public Menu 
{

protected:

	Table table ;
	
	Date getDateFromScreen();
	int display2();
		
	Student checkThisStudent(string name);

public:

	AddTABMenu();
	~AddTABMenu();
	AddTABMenu(const AddTABMenu&);

	void display();

	Table getTable();

};

#endif

