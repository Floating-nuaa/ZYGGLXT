#ifndef  LESSON_H_
#define LESSON_H_
#include "Date.h"
class Lesson :public Date

	//这是一个课程类，是Date的子类，包含课的日期和第几节的信息

{
private:

	int ordinalNumber;//记录这是第几节课
    

public:

    Lesson();
    
    Lesson(int year, int month, int day,int ordinalNumber);//普普通通的构造函数
    
    Lesson(int month, int day,int ordinalNumber);//重载构造函数，缺省年的构造
    
    Lesson(const Lesson& obj);//拷贝构造函数
    
    Lesson(const Date& obj, int num);//日期和课程节数进行构造

    bool operator <(const Lesson& obj)const;
    
    //这个很重要，为了避免使用比较函数，
    //这里把小于号重载为大于号，再Table中就能实现小根堆

    void display();//演示一下

    int getOriginalNumber();//返回这是第几节课

    bool operator !=(const Lesson&)const;
};
#endif 
