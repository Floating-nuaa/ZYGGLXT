#include "Money.h"
#include <iostream>
using namespace std;
Money::Money() 

{
	sum = 0;
	currencyUnit = "RMB";
}

Money::~Money() {}

Money::Money(int a, string CU) {
	sum = a;
	currencyUnit = CU;
}

Money::Money(const Money& obj) 
{
	sum = obj.sum;
	currencyUnit = obj.currencyUnit;
}

void Money::setNum(int a) 
{
	sum = a;
}
int Money::getNum() 

{
	return sum;
}

void Money::display() 
{
	cout << " " << sum << " " << currencyUnit;
}