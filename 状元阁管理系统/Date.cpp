#include "Date.h"

//先声明两个后边会用到的函数

int monthHowDays(int year, int month);
bool isRunYear(int x);



Date::Date(int year, int month, int day) 

{
    this->year = year;
    this->month = month;
    this->day = day;
    Simplify();
}

Date::Date(int month, int day) 
{
    this->month = month;
    this->day = day;
    this->year = 2020;
    Simplify();
}

Date::Date()
{
    year = 2020;
    month = 1;
    day = 1;
}

Date::Date(const Date& obj) 
{
    year = obj.year;
    month = obj.month;
    day = obj.day;
}



void Date::display() 
{
    cout << "日期： " << year;
    cout << setw(4) << month;
    cout << setw(4) << day<<"   ";
}



int Date :: operator -(const Date& obj)

//重载Date中的运算符，忘了咋重载了，先等等

{

    if (*this < obj) return -1;//先判断日期大小，要是小的减去大的就返回-1;

    int ans = 0;//记录有多少天

    for (int i = obj.year; i <= year; i++) //循环年
    {
        if (i == obj.year)
        {// 第一次进入循循环年的话
            for (int j = obj.month; j <= 12; j++)//循环月份
            {
                if (j == obj.month && j < month)
                {//循环的第一个月，而且没到被减数的月份
                    for (int k = obj.day; k <= monthHowDays(i, j); k++)
                        ans++;
                    //这一天开始，加到月底
                }
                else if (i == year && j == obj.month && j == month)
                {//同一个月内的话,目标年
                    for (int k = obj.day; k <= this->day; k++)
                        ans++;
                    //起点加到终点
                    return ans;
                }
                else if (j < month)
                {//经过了j++ ，循环到了下个月，而且没到目标月
                    for (int k = 1; k <= monthHowDays(i, j); k++)
                        ans++;
                    // 从一号加到月底
                }
                else if (i == year && j == month && j != obj.month) {
                    //是目标年,经过了j++，到了要加的最后一个月，
                    for (int k = 1; k <= this->day; k++)
                        ans++;
                    return ans;
                    //从一号加到目标天数
                }
                else if (j == obj.month) {
                    for (int k = obj.day; k <= monthHowDays(i, j); k++)
                        ans++;
                }
                else
                {
                    for (int k = 1; k <= monthHowDays(i, j); k++)
                        ans++;
                }
            }
        }

        else if (i != obj.year)
        {
            //当有跨年存在时
            for (int j = 1; j <= 12; j++)//循环月份
            {
                if (j == month && i == year)
                {//到了目标月份
                    for (int k = 1; k <= this->day; k++)
                        ans++;
                    return ans;
                    //起点加到终点
                }
                else
                {
                    for (int k = 1; k <= monthHowDays(i, j); k++)
                        ans++;
                }
            }
        }
    }

    //全都加完了
    return ans;
}


Date Date::operator +(int x) {//x是多少节课，所以要--
    x--;
    day += x;

    while (Simplify());//加上天数，直至完全简化

    return *this;
}


Date Date::operator =(const Date& obj) {
    year = obj.year;
    month = obj.month;
    day = obj.day;
    return *this;
}



bool Date ::operator >(const Date& obj)const {
    int a = year - obj.year;
    if (a > 0)return 1;
    if (a < 0)return 0;
    if (a == 0) {
        int b = month - obj.month;
        if (b > 0)return 1;
        if (b < 0)return 0;
        if (b == 0) {
            int c = day - obj.day;
            if (c > 0)return 1;
            if (c < 0)return 0;
            if (c == 0)return 0;
        }
    }
    return 0;

}

bool Date ::operator ==(const Date& obj)const 

{

    if (year == obj.year && month == obj.month && day == obj.day) 
    {
        return 1;
    }
       
    return 0;
}

bool Date ::operator <(const Date& obj)const {
    int a = year - obj.year;
    if (a > 0)return 0;
    if (a < 0)return 1;
    if (a == 0) {
        int b = month - obj.month;
        if (b > 0)return 0;
        if (b < 0)return 1;
        if (b == 0) {
            int c = day - obj.day;
            if (c > 0)return 0;
            if (c < 0)return 1;
            if (c == 0)return 0;
        }
    }
    return 0;
}

bool Date ::operator<=(const Date& obj)const 

{

    if (*this == obj) 
    {
        return 1;
    }

    if (*this < obj) 
    {
        return 1;
    }

    return 0;

}

bool Date ::operator>=(const Date& obj)const

{
    if (*this == obj)
    {
        return 1;
    }

    if (*this > obj)
    {
        return 1;
    }

    return 0;

}



Date Date::operator++()

//重载前置++

{
    this->day++;
    Simplify();
    return *this;

}

Date Date::operator++(int) 
//重载后置++
{
    Date temp(*this);
    this->day++;
    Simplify();
    return temp;
}

Date Date::operator--(int) 

//重载后置--

{
    Date temp(*this);
    this->day--;
    Simplify();
    return temp;

}

Date Date::operator--()

//重载前置--

{
    this->day--;
    Simplify();
    return *this;
}




int Date::getYear() { return year; }
int Date::getMonth() { return month; }
int Date::getDay() { return day; }



bool Date::Simplify() {
    if (month > 12)
    {
        year += 1;
        month -= 12;
    }
    int a = monthHowDays(year, month);//提取这个月有几天
    if (day > a)
    {
        day -= a;
        month += 1;
    }
    a = monthHowDays(year, month);
    if (day > a || month > 12)return 1;//没有完全简化
    return 0;//完全简化了
}



bool isRunYear(int x) {
    //判断是否为闰年的函数，是返回1，不是返回0；
    if (x % 4 != 0) return 0;
    else if (x % 4 == 0) {
        if (x % 100 == 0 && x % 400 != 0) {
            return 0;
        }
        else return 1;
    }
}



int monthHowDays(int year, int month) {
    //判断这个月有几天
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else if (month == 2) {
        if (isRunYear(year))
            //如果是闰年
            return 29;

        else
            //不是闰年的话
            return 28;
    }
}









