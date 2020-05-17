#include "People.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

int People::numID = 1;//初始化ID,后续从文件中读取

People::People(char* name, char sex, char* phone) :ID(numID)
{
	strcpy_s(this->name, name);
	this->gender = sex;
	strcpy_s(this->phone, phone);
	numID++;
}

People::People(char* name, char* phone,char sex):ID(numID)
{
	this->gender = sex;
	strcpy_s(this->name, name);
	strcpy_s(this->phone, phone);
	numID++;
}

People::People(char* name) : ID(numID)
{
	strcpy_s(this->name, name);
	numID++;
	this->gender = '.';
	char nnn[5] = "?";
	strcpy_s(this->phone,nnn );
}

People::People(const People& obj):ID(obj.ID)
{
	strcpy_s(this->name, obj.name);
	strcpy_s(this->phone, obj.phone);
	this->gender = obj.gender;
}

People::People(char* name, char sex):ID(numID) {
	strcpy_s(this->name, name);
	numID++;
	this->gender = sex;
	char pho[10] = "?";
	strcpy_s(this->phone, pho);
}

People::People() :ID(-1)
{
	gender = '0';
	strcpy_s(name, "test");
	strcpy_s(phone, "test");
}

void People::display() 
{
	cout << "姓名      " << name << endl;
	cout << "性别      " << gender << endl;
	cout << "电话号码  " << phone << endl;
	cout << "ID        " << ID << endl;
}

void People::setGender(char sex) 
{
	this->gender = sex;
	return;
}

void People::setName(char* name) 
{
	strcpy_s(this->name, name);
	return;
}

void People::setPhone(char *phone)
{
	strcpy_s(this->phone, phone);
}

int People::checkNumID() 
{
	return numID;
}




char* People::getName() 

{
	return name;
}

char People::getGender() 

{
	return gender;
}

char* People::getPhone()

{
	return phone; 
}

int People::getID()

{
	return this->ID; 
}

People People::operator =(const People& obj) 
{
	strcpy_s(this->name, obj.name);
	strcpy_s(this->phone, obj.phone);
	this->gender = obj.gender;
	this->ID = obj.ID;
	return *this;
}