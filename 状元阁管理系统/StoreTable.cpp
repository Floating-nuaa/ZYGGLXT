#include "StoreTable.h"

StoreTable::~StoreTable(){}

StoreTable::StoreTable():lessonTable()
{

	this->num = 0;
}

StoreTable::StoreTable(const StoreTable& obj) 

{
	this->num = obj.num;
	
	for (int i = 0; i < obj.num; i++) 
	
	{
		this->lessonTable[i] = obj.lessonTable[i];
	}

}
void StoreTable::buildStoreTable(Table tab) 
{
	this->num = tab.lessonTimeTable.size();
	register int i = 0;
	while (!tab.lessonTimeTable.empty())
	{
		lessonTable[i] = tab.lessonTimeTable.top();
		tab.lessonTimeTable.pop();
		i++;
	}
}

StoreTable::StoreTable(Table &tab)

{
	
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

