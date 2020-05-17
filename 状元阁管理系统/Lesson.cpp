#include "Lesson.h"
#include "Date.h"



Lesson::Lesson()
{
	Date::Date();
	ordinalNumber = 0;
}

Lesson::Lesson(int year, int month, int day, int ordinalNumber):Date(year,month,day)

//普普通通的构造函数

{
	Date::Date(year, month, day);
	string expect1;
	try 
	{
		if (ordinalNumber > 5 || ordinalNumber <= 0)
		{
			expect1 = "课程时间输入异常!!!";
			throw expect1;
		}


	}
	catch (string goal)
	{
		cout << goal << endl;
	}

	this->ordinalNumber = ordinalNumber;
	
}

Lesson::Lesson(int month, int day, int ordinalNumber):Date( month, day)

//重载构造函数，缺省年的构造

{
	Date::Date(month, day);
	string expect1;
	try
	{
		if (ordinalNumber > 5 || ordinalNumber <= 0)
		{
			expect1 = "课时间输入异常!!!";
			throw expect1;
		}	
	}
	catch (string goal)
	{
		cout << goal << endl;
	}

	this->ordinalNumber = ordinalNumber;
	
}

Lesson::Lesson(const Lesson& obj) : Date(obj)

//拷贝构造函数
{

	Date::Date(obj);
	//cout << "Lesson 拷贝"<<endl;
	this->ordinalNumber = obj.ordinalNumber;

}

Lesson::Lesson(const Date& obj, int num):Date(obj)

{
	this->ordinalNumber = num;
	Date::Date(obj);
	string expect1;
	try
	{
		if (ordinalNumber > 5 || ordinalNumber <= 0)
		{
			expect1 = "课程序数输入异常!!!";
			throw expect1;
		}
	}
	catch (string goal)
	{
		cout << goal << endl;
	}

	
	
	//cout << "日期构造函数！" << endl;
}

void Lesson::display()

//演示一下

{
	Date::display();
	cout <<"第 "<< ordinalNumber <<"节"<< endl;
}

bool Lesson::operator <(const Lesson& obj)const

	//这个很重要，为了避免使用比较函数
	//这里把小于号重载为大于号，就能在Table里边实现小根堆
	//从而实现可变的排列顺序是从小日期到大日期

{
	int a = year - obj.year;

	if (a > 0)return 1;
	if (a < 0)return 0;
	
	if (a == 0) 
	{
		int b = month - obj.month;
		
		if (b > 0)return 1;
		if (b < 0)return 0;
		
		if (b == 0) 
		{
			int c = day - obj.day;
		
			if (c > 0)return 1;
			
			if (c < 0)return 0;
			
			if (c == 0)return 0;
		}
	}

	if (this->ordinalNumber >= obj.ordinalNumber) 
		//课程节数的比较，效地在前，不理解看上一条注释	
	{
		return 1;
	}
	//否则都是返回0
	return 0;
}

int Lesson::getOriginalNumber() 
{
	return this->ordinalNumber;
}

bool Lesson::operator !=(const Lesson& obj)const 
{
	if (this->day != obj.day)
	{
		return true;
	}
	if (this->month != obj.month)
	{
		return true;
	}
	if (this->ordinalNumber != obj.ordinalNumber)
	{
		return true;
	}

	return false;


}

