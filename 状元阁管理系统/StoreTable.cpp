#include "StoreTable.h"



StoreTable::~StoreTable(){}



StoreTable::StoreTable():lessonTable()

{
	this->classType = 1;
	strcpy_s(this->theOtherName, "test");
	this->num = 0;
	string str = "学生Test的课表";
	strcpy_s(this->selfName, str.c_str());

}

StoreTable::StoreTable(const StoreTable& obj) 

{
	this->classType = obj.classType;

	strcpy_s(this->selfName, obj.selfName);

	strcpy_s(this->theOtherName, obj.theOtherName);

	this->num = obj.num;
	
	for (int i = 0; i < obj.num; i++) 
	
	{
		this->lessonTable[i] = obj.lessonTable[i];
	}

}

StoreTable::StoreTable(Table tab)

{
	this->classType = tab.classType;

	strcpy_s(this->selfName, tab.getSelfName().c_str());

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



void StoreTable::buildStoreTable(Table tab)

{
	this->classType = tab.classType;

	strcpy_s(this->selfName, tab.getSelfName().c_str());

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



void StoreTable:: setOtherName(string name) 
{
	
	strcpy_s(this->theOtherName, name.c_str());
	return ; 
}



string StoreTable::GetTheOtherName() 
{
	string ss(this->theOtherName);
	return ss;
}

Lesson* StoreTable:: getLessonTable() 


{
	return this->lessonTable;
}

int StoreTable::getNum() 

{
	return this->num;
}

int StoreTable::getClassType()
{
	return this->classType;
}

