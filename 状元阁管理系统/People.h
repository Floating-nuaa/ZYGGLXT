#ifndef PEOPLE_H_
#define PEOPLE_H_
#include "People.h"
#include <iostream>
using namespace std;
class People
{//这是一个抽象类
private:
    
    static int numID;//静态的，一个人一个ID

protected:
    
    char name[15];//姓名
    char gender;//性别
    char phone[20];//电话号码
    const int ID;//状元阁唯一识别号,不可更改

public:
    
    People(char* name, char sex, char* phone);
    People(char*name, char* phone,char sex='.');
    People(char* name);
    People(char* name, char sex);
    People(const People&);

    static int checkNumID();
    
    void setName(char *);
    void setGender(char sex);
    void setPhone(char *);
    void display();
    //virtual void showInScreen() = 0;
    
};
#endif