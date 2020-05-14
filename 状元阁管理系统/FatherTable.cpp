#include "FatherTable.h"
#include <string>
#include <iostream>
using namespace std;


FatherTable::FatherTable(People* peo) 

{

	strcpy_s(this->ownerName, peo->getName());
	
	this->ownerID = peo->getID();

	string ss(peo->getName());
	selfName = ss+"的FatherTable";

}

FatherTable::FatherTable() 

{
	
	char name[20] = "实验的机器人";
	People pe(name);
	strcpy_s(this->ownerName, pe.getName());
	string ss = "机器人的";
	selfName = ss+"FatherTable";

}

FatherTable::FatherTable(const FatherTable& obj) 

{
	this->ownerID = obj.ownerID;
	strcpy_s(this->ownerName, obj.ownerName);
	this->selfName = obj.selfName;
}



FatherTable FatherTable::operator=(const FatherTable& obj)

{
	this->ownerID = obj.ownerID;
	strcpy_s(this->ownerName, obj.ownerName);
	this->selfName = obj.selfName;
	return *this;
}



void FatherTable::display() 
{
	cout << selfName<<endl;
}



string FatherTable::getSelfName()

//注意这是一个虚函数，子类调用返回子类的selfName
{	

	return selfName;
}



string FatherTable::getOwnerName()
{
	string name(this->ownerName);
	return name;
}



int FatherTable::getOwnerID() 
{
	return this->ownerID;
}




