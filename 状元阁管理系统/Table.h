#ifndef TABLE_H_
#define TABLE_H_
#include "Lesson.h"
#include "People.h"
#include "Purpose.h"
#include <queue>



class Table 

    //课表类，每个课表记录学生的ID 和 姓名 

{

protected:

    int number;//课程节数

    Date startDate;

    Date endDate;

    priority_queue <Lesson> lessonTimeTable;

    //这是一个优先队列，存放日期
    
    char name[20];//所有者姓名
    
    int ID;//所有者的状元阁唯一识别号

public:
    
    //构造函数
    Table(People*, Date startDate, Date endDate,int num);//起止时间，推入队列
    
    Table(People*);//只传入人，然后进行输入课表，推入队列
    
    Table(People*, Date startDate, int x,int num);//开始时间，课程节数
    
    Table();
    
    void display();//展示一下课表

};
#endif 



