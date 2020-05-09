#ifndef  MONEY_H_
#define MONEY_H_
#include <string>
using namespace std;
class Money

	//货币类，不直接用int，主要为了避免错误的读取
	//也可以派生出接下来的账单交易等类
{
protected:

	int sum;//在这个系统中只需要整型即可
	string currencyUnit;//货币单位

public:
	Money();
	~Money();
	Money(int a, string CU = "RMB");
	Money(const Money& obj);
	void setNum(int );
	int getNum();
	void setUnit(string);
	string getUnit();
	void display();
};
#endif // ! MONEY_H_
