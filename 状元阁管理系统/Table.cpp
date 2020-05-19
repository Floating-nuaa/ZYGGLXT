#include "Table.h"
#include "People.h"
#include "Lesson.h"
#include <string>

#include <iostream>
using namespace std;


Table::Table(People* peo, Date startDate, Date endDate,int num,char* name, int Type)
	:FatherTable(peo)

				//起止时间，推入队列,从开始到结束推入

{
	this->tableID = -1;
	this->classType = Type;
	strcpy_s(this->theOtherName, name);
	if (num > 5)
	{
		cout << "请注意，课程时间超出正常范围！" << endl;
	}
	string str = peo->getName();//获得表格拥有着
	selfName = "学生: "+ str+" 的课表 ";

	this -> number = endDate - startDate;

	
	for (Date i = startDate; i <= endDate; i++) 
	
		//按照日期进行循环推入，内部构造临时的对象

	{
			Lesson lesson(i, num);
			lessonTimeTable.push(lesson);	
	}

}

Table::Table(People* peo, char* name, int Type):FatherTable(peo)

	//只传入人，然后进行输入课表，推入队列

{
	this->tableID = -1;
	this->classType = Type;
	string str = peo->getName();//获得表格拥有着
	selfName = "学生: " + str + " 的课表 ";

	strcpy_s(this->theOtherName, name);

	this->number = 0;
	
	int year = 2020, month, day, num=1;
	
	string expect1;
	try {

		cout << "请输入第一节课的月份： ";
		cin >> month;
		cout << endl;
		
		if (month >12||month<=0) 
		{
			expect1 = "月份输入异常！！！";
			throw expect1;
		}
		
		cout << "请输入第一节课日期： ";
		cin >> day;
		cout << endl;
		if (day > 31 || day <= 0)
		{
			expect1 = "日期输入异常!!!";
			throw expect1;
		}
		
		cout << "请输入是第几节课： ";
		cin >> num;
		cout << endl;
		if (num > 6 || num <= 0)
		{
			expect1 = "课程序数输入异常!!!";
			throw expect1;
		}
	}
	
	catch (char* esp)
	{
		printf("%s", esp);
	}

	/*Lesson lesson(year, month, day, num);
	lessonTimeTable.push(lesson);
	this->number++;*/
	
	cout << "请继续输入日期，输入  0  时结束" << endl;
	
	while (1) 
	{
		if (day == 0)
		
		{
			break;
		}
		
		if (day == 1)
		{
			month++;
		}
		
		Lesson lesson(year, month, day, num);
		lessonTimeTable.push(lesson);
		this->number++;

		cin >> day;
	}


}

Table::Table(People* peo, Date startDate, int x,int num, char* name, int Type)
	:FatherTable(peo)
	
	//开始时间，课程节数,x是有几节课，num是第几节课

{
	this->tableID = -1;
	this->classType = Type;

	string str = peo->getName();//获得表格拥有着

	selfName = "学生: " + str + " 的课表 ";

	strcpy_s(this->theOtherName, name);

	if (num > 5)
	{
		cout << "请注意，课程时间超出正常范围！" << endl;
	}

	this->number = x;

	int cnt = 0;
	for (Date i=startDate;cnt<x ; i++) 
	{
		Lesson lesson(i, num);
		lessonTimeTable.push(lesson);
		cnt++;
	}

}

Table::Table() :FatherTable( )
{
	/* name[20] = "实验的机器人";
	People pe(name);
	strcpy_s(this->name, pe.getName());
	this->ID = pe.getID();
	*/
	this->tableID = -1;
	this->classType = 1;
	strcpy_s(this->theOtherName, "test");

	selfName = "学生: test 的课表 ";
	
	this -> number = 0;


}



Table::Table(const Table& obj):FatherTable(obj)
{
	this->tableID = obj.tableID;
	this->classType = obj.classType;
	this->endDate = obj.endDate;
	this->startDate = obj.startDate;
	this->lessonTimeTable = obj.lessonTimeTable;
	this->number = obj.number;
	strcpy_s(this->theOtherName, obj.theOtherName);
}



Table::Table(StoreTable& obj) 

{
	this->tableID = obj.tableID;
	strcpy_s(this->ownerName, obj.ownerName);
	this->ownerID = obj.ownerID;

	this->classType = obj.classType;

	this->selfName = obj.selfName;

	strcpy_s(this->theOtherName, obj.theOtherName);

	this->number = obj.num;

	for (int i = 0; i < obj.num; i++) 
	{
		this->lessonTimeTable.push(obj.lessonTable[i]);
	}

		//注意这里是子类给父类赋值
		//其实这两个信息没什么用，都在优先队列里

	startDate = obj.lessonTable[0];
		//endDate是不需要的信息，为了避免警告将其初始化
	endDate = obj.lessonTable[0];

}



void Table::translateFromStoreTable(StoreTable& obj) 

{
	this->tableID = obj.tableID;
	strcpy_s(this->ownerName, obj.ownerName);
	
	this->ownerID = obj.ownerID;

	this->classType = obj.classType;

	this->selfName = obj.selfName;

	strcpy_s(this->theOtherName, obj.theOtherName);
	
	this->number = obj.num;

	for (int i = 0; i < obj.num; i++)
	{
		this->lessonTimeTable.push(obj.lessonTable[i]);
	}
	
	startDate = obj.lessonTable[0];

	//endDate是不需要的信息，为了避免警告将其初始化
	endDate = obj.lessonTable[0];

}



Table Table::operator=(const Table& obj) 
{
	this->tableID = obj.tableID;
	this->classType = obj.classType;

	FatherTable ::operator=(obj);

	this->endDate = obj.endDate;
	this->startDate = obj.startDate;
	this->lessonTimeTable = obj.lessonTimeTable;
	this->number = obj.number;
	strcpy_s(this->theOtherName, obj.theOtherName);
	return *this;

}



void Table::displaySTD() 

//展示一下课表

{
	Table objTab(*this);

	cout << "学生  " << this->ownerName << "  的课表" << endl;

	string TYPE = translateNumToClassType(this->classType);
	
	cout << "教师是   :  " << this->theOtherName << endl;
	cout << "课程类型 :  " << TYPE << endl;
	cout << "课程节数 :  " << this->number << endl;

	while(!objTab.lessonTimeTable.empty())

	//循环拿出优先队列中的课程
	
	{

		Lesson lesson (objTab.lessonTimeTable.top());

		lesson.display();
		
		objTab.lessonTimeTable.pop();

	}

}

void Table::displayTEA()

//展示一下课表

{
	Table objTab(*this);

	cout << "教师  " << this->ownerName << "  的课表" << endl;

	string TYPE = translateNumToClassType(this->classType);

	cout << "该节课学生是 :  " << this->theOtherName << endl;
	cout << "课程类型 :  " << TYPE << endl;
	cout << "课程节数： " << this->number << endl;

	while (!objTab.lessonTimeTable.empty())

		//循环拿出优先队列中的课程

	{

		Lesson lesson(objTab.lessonTimeTable.top());

		lesson.display();

		objTab.lessonTimeTable.pop();

	}

}




void Table::shortShowSTD()
{
	//简短展示学生表头信息
	cout << "学生  " << this->ownerName << "  的课表" << endl;


	string TYPE = translateNumToClassType(this->classType);

	cout << "教师是   :  " << this->theOtherName << endl;
	cout << "课程类型 :  " << TYPE << endl;
	cout << "课程节数 :  " << this->number << endl;
	
}

void Table:: shortShowTEA() 
{
	//简短展示老师表头信息
	cout << "教师  " << this->ownerName << "  的课表" << endl;


	string TYPE = translateNumToClassType(this->classType);

	cout << "该节课学生是 :  " << this->theOtherName << endl;
	cout << "课程类型 :  " << TYPE << endl;
	cout << "课程节数： " << this->number << endl;

}
void Table::shortShortShowTEA() 
{


	string TYPE = translateNumToClassType(this->classType);

	cout << setw(5) << this->theOtherName;
	cout << setw(10) << TYPE;
	cout << setw(5) << this->number << "节" << endl;

}



void Table::ReviseTeam() 

{
	string str = this->theOtherName;

	selfName = "教师: " + str + " 的课表 ";
	
	char TempName[30];
	strcpy_s(TempName, this->ownerName);
	strcpy_s(this->ownerName, this->theOtherName);
	strcpy_s(this->theOtherName, TempName);

}

void Table::ReviseTeamToSTD()

{
	string str = this->theOtherName;

	selfName = "学生: " + str + " 的课表 ";

	char TempName[30];

	strcpy_s(TempName, this->ownerName);
	strcpy_s(this->ownerName, this->theOtherName);
	strcpy_s(this->theOtherName, TempName);

}



void Table::clearThisTable() 
{
	//循环清空队列里的课程
	while (!lessonTimeTable.empty())
	{
		lessonTimeTable.pop();
	}
}

string Table::getSelfName()
{
	return this->selfName;
}



int Table::getClassType() 
{
	return this->classType;
}



string Table::getTheOtherName() 
{
	string str = this->theOtherName;
	return str;
}



int Table::getNum() 

{
	return this->number;
}



int Table::getTableID() 
{
	return this->tableID;
}
