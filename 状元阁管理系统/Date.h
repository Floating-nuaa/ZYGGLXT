#ifndef DATE_A_
#define DATE_A_
#include <iostream>
#include <iomanip>
using namespace std;


class Date {
    //日期类，包含月日年,主要功能是记录课在哪天上

protected:
    int year;
    int month;
    int day;

public:

    Date();
    Date(int year, int month, int day);//普普通通的构造函数
    Date(int month, int day);//重载构造函数，缺省年的构造
    Date(const Date& obj);//拷贝构造函数

    void display();//演示一下
    
    int operator - (const Date& obj);//重载+ - = ，日期相减返回整数，日期加整数返回日期

    Date operator + (int x);

    Date operator =(const Date& obj);//赋值号，按位赋值

    bool operator >(const Date& obj)const;//重载大于小于和等于

    bool operator <(const Date& obj)const;

    bool operator ==(const Date& obj)const;

    bool operator <= (const Date& obj)const;

    bool operator >=(const Date& obj)const;

    Date operator ++ (int);//重载后置++

    Date operator ++ ();//重载前置++

    Date operator --(int );//重载后置--

    Date operator --();//重载前置--

    int getYear();

    int getMonth();

    int getDay();

    bool Simplify();//进行加法后简化，向月份和年份上加；

};

#endif