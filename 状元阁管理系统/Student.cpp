#include "People.h"
#include "Table.h"
#include "Student.h"
#include "Purpose.h"
#include <string>
#include <string.h>
using namespace std;
Student::Student(char* name, char sex, char* phone, char* QQ, Purpose subj, string requirement , int downpayment )
	:People(name,sex,phone)
{
	strcpy_s(this->QQ, QQ);
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
}
Student::Student(char* name, char sex, char* phone, Purpose subj,string requirement , int downpayment )
	:People(name,sex,phone) 
{
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
	this->downPayment = downpayment;
}
Student::Student(char* name, char* phone, Purpose subj, string requirement , int downpayment ) 
:People (name,phone)
{
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
	this->downPayment = downpayment;

}

Student::Student(char* name, Purpose subj, string requirement, int downpayment )
	:People(name) 
{
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
	this->downPayment = downpayment;

}

Student::Student(char* name, char sex, Purpose subj, string requirement , int downpayment)
	:People(name,sex)
{
	this->sub = subj;
	this->requirement = requirement;
	this->downPayment = downpayment;
	this->downPayment = downpayment;

}

Student::Student(const Student& obj) :People(obj)
{
	strcpy_s(this->QQ, QQ);
	this->sub = obj.sub;
	this->requirement = obj.requirement;
	this->downPayment = obj.downPayment;
}
void Student::display() 
{
	People::display();
	sub.display();
	cout << requirement << " " << downPayment << endl;
}