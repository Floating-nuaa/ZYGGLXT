#ifndef STUDENT_H_
#define STUDENT_H_
#include "People.h"
#include "Purpose.h"
#include "Date.h"
#include <string>

class Student : public People {

	//学生类，是People 的派生类,已经有的的成员有，name,ID,gender,phone ，phone 是家长的手机号

	//还要记录学生的QQ号，科目（内置分数），学生的其他要求，是否缴纳了定金


private:

	char QQ[20];
	int downPayment;//预付订金
	Purpose sub;//科目
	char requirement[100];//学生的要求

public:

	//四个构造函数，分别需要
	//姓名 性别 电话 QQ 科目 要求 定金
	//姓名 性别 电话 科目 要求 定金
	//姓名 电话 科目 要求 定金
	//姓名 科目 要求 定金
	//姓名 性别 科目 要求 定金
	//最后两项都是缺省构造

	Student(char*, char, char*, char*, Purpose, string requirement = "无", int downpayment = 0);

	Student(char*, char, char*, Purpose, string requirement = "无", int downpayment = 0);

	Student(char*, char*, Purpose, string requirement = "无", int downpayment = 0);

	Student(char*, Purpose, string requirement = "无", int downpayment = 0);

	Student(char*, char, Purpose, string requirement = "无", int downPayment = 0);

	Student();

	Student(const Student& obj);//拷贝构造函数

	Student operator = (const Student obj);

	void display();

	void setQQ(char*);

	void setDownPayment(int);

	void setRequirement(string);

	friend class OperateSTD;

	int getDownPayment();
};
#endif;