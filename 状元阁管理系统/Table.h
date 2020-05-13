/******************************************************************
                 这是Table类
    
    课表类,继承了FatherTable，拥有所有者信息和表头信息 
    增加课程节数，起止时间，和课程信息，教学组合姓名

    增加教学组合姓名的原因是可以记录师生的教学关系，也可以直接生成
    两份课表，分别进行储存，都用人的姓名进行命名

*******************************************************************/
#ifndef TABLE_H_
#define TABLE_H_
#include "Lesson.h"
#include "People.h"
#include "Purpose.h"
#include "FatherTable.h"
#include <queue>
#include "StoreTable.h"


class Table : public FatherTable 

{

protected:

    char theOtherName[15];

    int number;//课程节数

    Date startDate;
    Date endDate;

    priority_queue <Lesson> lessonTimeTable;

    //这是一个优先队列，存放日期
    
    
public:
    
    friend class StoreTable;

    //构造函数

    Table(People*, Date startDate, Date endDate,int num, char* name);
    //起止时间，推入队列
    
    Table(People*, char* name);
    //只传入人，然后进行输入课表，推入队列
    
    Table(People*, Date startDate, int x,int num, char* name);
    //开始时间，课程节数
    
    Table();
    
    Table( StoreTable& );

    void ReviseTeam();

    void translateFromStoreTable(StoreTable&);

    void displaySTD();  //展示学生课表

    void displayTEA();  //展示老师课表
    
    int getNum();
    
};
#endif 



