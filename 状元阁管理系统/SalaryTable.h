#ifndef SALARYTABLE_H_
#define SALARYTABLE_H_
#include "OperateTable.h"
#include "Student.h"
#include "Teacher.h"
#include "ConClassPrice.h"
/*********************************************************
教师的工资表，属于数据层
*********************************************************/

class SalaryTable 

{
protected:
	
	int totalSalary;		//总薪水

	Teacher teacher;		//老师的数据

	void caculateSalary();  //计算总薪水
	
	
	int HowMuchInShort();

	int getClassTypeOutPrice(int key);

	int HowMuchInDisplay();

public:
	
	SalaryTable(Teacher &);
	
	SalaryTable(const SalaryTable&);
	
	~SalaryTable();
	
	SalaryTable operator =(const SalaryTable&);

	void showAllTable();	//展示这位老师的所有课表
	void briefShow();		//进行简短的展示

};
#endif // !SALARYTABLE_H_


