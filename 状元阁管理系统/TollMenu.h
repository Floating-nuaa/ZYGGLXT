#ifndef  TOLLMENU_H_
#define TOLLMENU_H_
#include "Menu.h"
#include "TransactionRecord.h"
#include "STDInfo.h"

/******************************************************************
	收银菜单

	通过学生姓名，查找学生的数据,寄存在学生的对象里
	获取操作者的对象信息
	获取所交的费用
	生成 TransactionRecord 对象

*******************************************************************/


class TollMenu :public Menu 

{
protected:

	//生成一个交易记录对象

	void catchAndAnylasis();

public:

	TollMenu();
	
	~TollMenu();
	
	void display();


	//返回一个记录
	TransactionRecord getTransactionRecord();

};


#endif // ! TOLLMENU_H_
