#ifndef  FATHER_TABLE_H_
#define FATHER_TABLE_H_
#include <string>
#include "People.h"
using namespace std;

class FatherTable 

	//这是一个表格类，拥有表头，所有者姓名，所有者ID
	//会派生出老师的课表和学生的课程表Table，老师的工资表 SalaryTable

{
protected :
	
	//char dataHeader[30];

	char name[20];//所有者姓名

	int ID;//所有者的状元阁唯一识别号

	string selfName;

public :

	FatherTable(People*);
	FatherTable();

	void display();//展示一下
	void saveFatherTable();//保存到文件中
	void updateFather();//更新FatherTable
	
	virtual string getSelfName();

};

#endif // ! FATHER_TABLE_H_

