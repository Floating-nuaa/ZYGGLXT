#include "StoreTable.h"

StoreTable::~StoreTable(){}

StoreTable::StoreTable():lessonTable()
{
	strcpy_s(this->theOtherName, "test");
	this->num = 0;
}

StoreTable::StoreTable(const StoreTable& obj) 

{
	strcpy_s(this->theOtherName, obj.theOtherName);

	this->num = obj.num;
	
	for (int i = 0; i < obj.num; i++) 
	
	{
		this->lessonTable[i] = obj.lessonTable[i];
	}

}

void StoreTable::buildStoreTable(Table tab)
{

	strcpy_s(theOtherName, tab.theOtherName);

	this->num = tab.lessonTimeTable.size();
	
	register int i = 0;
	
	while (!tab.lessonTimeTable.empty())
	{
		lessonTable[i] = tab.lessonTimeTable.top();
		tab.lessonTimeTable.pop();
		i++;
	}
}

StoreTable::StoreTable(Table tab)

{
	strcpy_s(this->theOtherName, tab.theOtherName);

	this->num = tab.lessonTimeTable.size();

	register int i=0;
	
	while (!tab.lessonTimeTable.empty()) 
	{
		lessonTable[i] = tab.lessonTimeTable.top();
		tab.lessonTimeTable.pop();
		i++;
	}

}

int StoreTable::getNum() 

{
	return this->num;
}

Lesson* StoreTable:: getLessonTable() 


{
	return this->lessonTable;
}

string StoreTable::GetTheOtherName() 
{
	string ss(this->theOtherName);
	return ss;
}

void StoreTable:: setOtherName(string name) 
{
	
	strcpy_s(this->theOtherName, name.c_str());
	return ; 
}

