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
#include "stdafx.h"
#include "StoreTable.h"


class Table : public FatherTable 

{

protected:

    //这是一个优先队列，存放课程
    priority_queue <Lesson> lessonTimeTable;
    
    Date startDate;

    Date endDate;
    
    int number;//课程节数

    char theOtherName[30];//配对教师姓名

    int classType;//记录课程类型
    
    int tableID;

public:

    
    friend class OperateTable;
    friend class StoreTable;

    //构造函数
    Table();

    Table(People*, Date startDate, Date endDate,int num, char* name,int Type);
    //起止时间，推入队列
    
    Table(People*, char* name, int Type);
    //只传入人，然后进行输入课表，推入队列
    
    Table(People*, Date startDate, int x,int num, char* name,int Type);
    //开始时间，课程节数

    Table(const Table&);

    Table( StoreTable& );
    
    Table operator =(const Table&);
    

    void ReviseTeam();

    void ReviseTeamToSTD();

    void translateFromStoreTable(StoreTable&);

    void displaySTD();  //展示学生课表

    void displayTEA();  //展示老师课表
    
    void shortShowSTD(); //简短展示学生表头信息
    
    void shortShowTEA(); //简短展示老师表头信息

    void shortShortShowTEA(); //精简的展示信息

    void clearThisTable(); //清空当前课表内的内容

    int getNum();// 获得课程节数

    string getSelfName();//获得表格名称

    int getClassType();//获得类型代号

    string getTheOtherName();//获得对应成员的姓名

    int getTableID();//获得课表的编号

};
#endif 



