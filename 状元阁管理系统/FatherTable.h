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

	char ownerName[20];//所有者姓名

	int ownerID;//所有者的状元阁唯一识别号

	string selfName;  //

public :

	FatherTable(People*);

	FatherTable();
	FatherTable(const FatherTable&);
	FatherTable operator=(const FatherTable&);
	void display();//展示一下
	
	virtual string getSelfName();

	string getOwnerName();

	int getOwnerID();
};

#endif // ! FATHER_TABLE_H_

