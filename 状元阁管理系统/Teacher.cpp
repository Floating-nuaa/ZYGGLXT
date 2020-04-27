#include "Teacher.h"
#include <string>
#include <string.h>

using namespace std;

Teacher::Teacher(char* name, char sex, char* phone, char* QQ, int salary) :People(name, sex, phone) {
	strcpy_s(this->QQ, QQ);
	this->salary = salary;
}



void Teacher::display() {
	People::display();
	cout << QQ << " " << salary << endl;
}



void Teacher::setQQ(char* QQ) {
	strcpy_s(this->QQ, QQ);
}



void Teacher::setSalary(int salary) {
	this->salary = salary;
}
