#ifndef TABLE_H_
#define TABLE_H_
#include "Date.h"
#include "People.h"
#include "Purpose.h"
#include <queue>
class Table {
protected:
    Purpose sub;//科目，这个其实不重要
    int number;//课程节数
    Date startDate;
    Date endDate;
    priority_queue <Date> classTable;//一个优先队列，用于存放日期
    //char whoseTable;课表属于谁,??这是什么来着
    char name[20];//所有者姓名
    int ID;//所有者的状元阁唯一识别号

public:
    //构造函数
    Table(People*, Date startDate, Date endDate);//起止时间，推入队列
    Table(People*);//只传入人，然后进行输入课表，推入队列
    Table(People*, Date startDate, int x);//开始时间，课程节数
    Table();
    void display();//展示一下课表

};
#endif 



