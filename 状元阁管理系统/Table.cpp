#include "Table.h"
#include "People.h"
#include "Lesson.h"
#include <string>

using namespace std;


Table::Table(People* peo, Date startDate, Date endDate,int num):FatherTable(peo)

				//起止时间，推入队列,从开始到结束推入

{
	if (num > 5)
	{
		cout << "请注意，课程时间超出正常范围！" << endl;
	}

	selfName = "StudentTable";

	this -> number = endDate - startDate;

	
	for (Date i = startDate; i <= endDate; i++) 
	
		//按照日期进行循环推入，内部构造临时的对象

	{
			Lesson lesson(i, num);
			lessonTimeTable.push(lesson);	
	}

}

Table::Table(People* peo) :FatherTable(peo)

	//只传入人，然后进行输入课表，推入队列

{
	
	selfName = "StudentTable";

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
		if (num > 5 || num <= 0)
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

Table::Table(People* peo, Date startDate, int x,int num) :FatherTable(peo)
	
	//开始时间，课程节数,x是有几节课，num是第几节课

{
	if (num > 5)
	{
		cout << "请注意，课程时间超出正常范围！" << endl;
	}

	selfName = "StudentTable";

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

	selfName = "StudentTable";
	
	this -> number = 0;


}


void Table::display() 

//展示一下课表

{
	FatherTable::display();

	cout << "课程节数： " << this->number << endl;

	while(!lessonTimeTable.empty())

	//循环拿出优先队列中的课程
	
	{

		Lesson lesson (lessonTimeTable.top());
		lesson.display();
		lessonTimeTable.pop();

	}

}
