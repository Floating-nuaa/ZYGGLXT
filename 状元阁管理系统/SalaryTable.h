#ifndef SALARYTABLE_H_
#define SALARYTABLE_H_
#include "FatherTable.h"
/*********************************************************
教师的工资表，属于数据层
*********************************************************/

class SalaryTable 

{
protected:

	char ownerName[20];//所有者姓名

	int ownerID;//所有者的状元阁唯一识别号
	
	int totalSalary; //总薪水

	void caculateSalary();  //计算总薪水
public:
	
	SalaryTable();
	~SalaryTable();
	void showAllTable();	//展示这位老师的所有课表
	void briefShow();		//进行简短的展示

};
#endif // !SALARYTABLE_H_
