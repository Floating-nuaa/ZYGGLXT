#include "Table.h"
#include "People.h"
#include "Lesson.h"
#include <string>

using namespace std;


Table::Table(People* peo, Date startDate, Date endDate,int num)

				//起止时间，推入队列,从开始到结束推入

{
	strcpy_s(this->name, peo->getName());

	this->ID = peo->getID();

	this -> number = endDate - startDate;

	
	for (Date i = startDate; i <= endDate; i++) 
	
		//按照日期进行循环推入，内部构造临时的对象

	{
		Lesson lesson(i, num);
		lessonTimeTable.push(lesson);
	}

}



Table::Table(People*) {
	//只传入人，然后进行输入课表，推入队列

}




Table::Table(People*, Date startDate, int x,int num) 
	
	//开始时间，课程节数

{
	

}




void Table::display() 

//展示一下课表

{
	cout << "课程节数： " << this->number << endl;

	while(!lessonTimeTable.empty())

	//循环拿出优先队列中的课程
	
	{

		Lesson lesson (lessonTimeTable.top());
		lesson.display();
		lessonTimeTable.pop();

	}

}
Table::Table() {

 }