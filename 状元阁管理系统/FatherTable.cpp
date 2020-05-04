#include "FatherTable.h"
#include <string>

using namespace std;


FatherTable::FatherTable(People* peo) 

{

	strcpy_s(this->name, peo->getName());
	this->ID = peo->getID();
	selfName = "FatherTable";

}

FatherTable::FatherTable() 

{
	
	char name[20] = "实验的机器人";
	People pe(name);
	strcpy_s(this->name, pe.getName());

	selfName = "FatherTable";

}
void FatherTable::display() 
{
	cout << this->name << "的"<<this->getSelfName()<<endl;
}

string FatherTable::getSelfName()

//注意这是一个虚函数，子类调用返回子类的selfName
{	

	return selfName;
}
