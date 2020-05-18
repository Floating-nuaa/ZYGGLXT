#ifndef  TOLLMENU_H_
#define TOLLMENU_H_
#include "Menu.h"
#include "TransactionRecord.h"
#include "STDInfo.h"
#include "stdafx.h"
#include "OperateSTD.h"
#include "RecordInfo.h"
#include "OperateTable.h"
#include "ConClassPrice.h"

/******************************************************************
	说明：这个类得封装性非常强，只对外部提供一个接口display
		  而且构造函数不可缺省
	收银菜单

	通过学生姓名，查找学生的数据,寄存在学生的对象里
	获取操作者的对象信息
	获取所交的费用
	生成 TransactionRecord 对象,保存在文件中
	最后修改时间 2020/5/11
*******************************************************************/


class TollMenu :public Menu 

{
protected:


	Manager operatorManager;

	bool display2();  //附加项目询问

	bool saveThisTranRecord(TransactionRecord );  
		//保存这个交易记录，只能内部访问
	
	Student checkSTDInfo(string STDname); 
		//通过学生姓名查询学生信息，并生成一个学生对象返回会来 
	int HowMuchToPay(Student &);

	int getClassTypeInPrice(int );

public:

	//生成交易菜单必须传入当前的操作者
	//否则不能生成这个对象

	TollMenu(Manager &);
	TollMenu(const TollMenu&);
	~TollMenu();
	
	void display();
	

};
#endif // ! TOLLMENU_H_
