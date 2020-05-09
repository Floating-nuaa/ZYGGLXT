#include "Teacher.h"
#include <string>
#include <string.h>

using namespace std;

Teacher::Teacher(char* name, char sex, char* phone, char* QQ, Purpose subj, int salary)
	:People(name, sex, phone) ,sub(subj)

{
	strcpy_s(this->QQ, QQ);
	this->salary = salary;
}

Teacher::Teacher() :People()
{
	strcpy_s(this->QQ, "Test");
	this->salary = 60;

}

Teacher::Teacher(const Teacher& obj) :People(obj),sub(obj.sub)

{
	strcpy_s(this->QQ, obj.QQ);
	this->salary = obj.salary;
}

Teacher::~Teacher(){}



void Teacher::display() 

{
	People::display();
	cout <<"QQ  "<< QQ << " " << salary << endl;
	sub.display();
}

void Teacher::setQQ(char* QQ) 

{
	strcpy_s(this->QQ, QQ);
}

void Teacher::setSalary(int salary) 
{
	this->salary = salary;
}


Teacher Teacher:: operator =(const Teacher& obj) 

{
	strcpy_s(this->name, obj.name);
	strcpy_s(this->QQ, obj.QQ);
	strcpy_s(this->phone, obj.phone);
	this->salary = obj.salary;
	this->gender = obj.gender;
	this->sub = obj.sub;
	return *this;
}

