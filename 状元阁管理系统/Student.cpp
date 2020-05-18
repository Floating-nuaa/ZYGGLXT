#include "People.h"
#include "Table.h"
#include "Student.h"
#include "Purpose.h"
#include <string>
#include <string.h>

using namespace std;



Student::Student(char* name, char sex, char* phone, char* QQ, Purpose subj, string requirement , int downpayment )
	:People(name,sex,phone),sub(subj)

{

	strcpy_s(this->QQ, QQ);
	this->downPayment = downpayment;
	strcpy_s(this->requirement, requirement.c_str());

}

Student::Student(char* name, char sex, char* phone, Purpose subj,string requirement , int downpayment )
	:People(name,sex,phone),sub(subj)
{
	strcpy_s(QQ, "无记录");
	strcpy_s(this->requirement, requirement.c_str());
	this->downPayment = downpayment;
	this->downPayment = downpayment;
}

Student::Student(char* name, char* phone, Purpose subj, string requirement , int downpayment ) 
:People (name,phone), sub(subj)
{
	
	strcpy_s(QQ, "无记录");
	strcpy_s(this->requirement, requirement.c_str());
	this->downPayment = downpayment;
	this->downPayment = downpayment;

}

Student::Student(char* name, Purpose subj, string requirement, int downpayment )
	:People(name) ,sub(subj)
{
	
	strcpy_s(QQ, "无记录");
	strcpy_s(this->requirement, requirement.c_str());
	this->downPayment = downpayment;
	this->downPayment = downpayment;

}

Student::Student(char* name, char sex, Purpose subj, string requirement , int downpayment)
	:People(name,sex),sub(subj)

{
	
	strcpy_s(QQ, "无记录");
	strcpy_s(this->requirement, requirement.c_str());
	
	this->downPayment = downpayment;

}

Student::Student(const Student& obj) :People(obj),sub(obj.sub)
{
	strcpy_s(this->QQ, obj.QQ);
	strcpy_s(this->requirement, obj.requirement); 
	this->downPayment = obj.downPayment;
}

Student::Student() :People() 
{
	strcpy_s(QQ, "Test");
	strcpy_s(requirement, "test");
	downPayment = 0;
}
/* char name[15];//姓名
    char gender;//性别
    char phone[20];//电话号码
    const int ID;//状元阁唯一识别号,不可更改
	char QQ[20];
	int downPayment;//预付订金
	Purpose sub;//科目
	string requirement;
	*/

	Student Student::operator = (const Student obj)

	//重载 =运算符
{
	People::operator=(obj);
	
	strcpy_s(this->QQ, obj.QQ);
	this->downPayment = obj.downPayment;
	this->sub = obj.sub;
	strcpy_s(this->requirement , obj.requirement);

	return *this;
}

void Student::display() 
{
	People::display();
	
	cout << "QQ        " << QQ << endl;
	cout << "特殊需求  " << requirement << endl;
	cout << "已交定金  " << downPayment << endl;
	
	sub.display();
}



void Student::setQQ(char* QQ) 
{
	strcpy_s(this->QQ, QQ);
}

void Student::setDownPayment(int DP)
{
	this->downPayment = DP;
}

void Student::setRequirement(string s)
{
	strcpy_s(requirement, s.c_str());
}

int Student:: getDownPayment()
{
	return this->downPayment;
}
