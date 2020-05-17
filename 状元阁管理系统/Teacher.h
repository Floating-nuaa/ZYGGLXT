#ifndef TEACHER_H_ 
#define TEACHER_H_
#include "Purpose.h"
#include "Table.h"
#include <vector>

class Teacher :public People {
	
	//老师类，是People 的派生类,
	//已经有的的成员有，name,ID,gender,phone ，phone 是老师的
	//还要记录老师的QQ号，科目，工资标准

private:
	
	char QQ[20];
	Purpose sub;//科目
	int salary;//工资标准

public:
	
	//构造函数 ， 添加老师只需一个构造函数，薪水为60
	//姓名 性别 phone QQ salary
	
	Teacher(char* name, char sex, char* phone, char* QQ, Purpose subj, int salary=60);
	Teacher(const Teacher& obj);
	Teacher();

	~Teacher();

	void setQQ(char*);
	
	void setSalary(int);
	
	void display();

	Teacher operator=(const Teacher& obj);

	friend class OperateTEA;


};
#endif

