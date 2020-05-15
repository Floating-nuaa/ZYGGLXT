#ifndef PEOPLE_H_
#define PEOPLE_H_

//#include "OperateSTD.h"

class People

    //这是一个抽象类

{
private:
    
    static int numID;//静态的，一个人一个ID

protected:
    
    char name[30];//姓名
    char gender;//性别
    char phone[20];//电话号码
    int ID;//状元阁唯一识别号,存入文件时候进行更新

public:
    
    People(char* name, char sex, char* phone);
    People(char*name, char* phone,char sex='F');
    People(char* name);
    People(char* name, char sex);
    People(const People&);
    
    People();
   
    
    
    virtual ~People(){}
    
    
    People operator =(const People&);
    
    static int checkNumID();
    
    void setName(char *);
    void setGender(char sex);
    void setPhone(char *);
    void display();
    char* getName();
    char getGender();
    char* getPhone();
    int getID();

   
    friend class OperateSTD;
    friend class OperateTEA;

};
#endif