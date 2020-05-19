#ifndef OPERATETABLE_H_
#define OPERATETABLE_H_
#include "OperateMode.h"
#include "Table.h"
#include "stdafx.h"
#include "TableInfo.h"	//保存文件的地址
#include "AddTABMenu.h"
class OperateTable : public OperateMode 
{
	//操作学生课表的类

protected :

	Table table;
	TableInfo saveAddress;

	bool checkIsThisTable();
	bool changeThisTable();
	bool addLesson();
	bool deleteLesson();

	int checkHowLongBelonging(Table TEATab);

public:

	OperateTable( Table &tab);
	OperateTable();
	~OperateTable();

	//对父类虚函数进行重写 

	virtual bool saveThisFile();		//保存当前文件，把当前的Table保存文件
	
	bool saveThisFile(int ruler);

	virtual bool readPreFile();			//读取前置文件，把数据读出到当前的Table
	
	bool readPreFile(string name);

	bool readPreFile(string name, int ordinal);//读出这个人的第几个课表
	
	bool updateThisTable();                //更新这个课表

	bool transformSTToCSV();

	bool transformTTToCSV();

	void getTableFromScreen();

	void clearHidenTable();
	
	Table getTable();			//返回这个让table对象

	string getAddress();
};
#endif // !OPERATETABLE_H_

