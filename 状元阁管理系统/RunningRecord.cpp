#include "RunningRecord.h"
#include <iostream>
#include <iomanip>
using namespace std;


RunningRecord::RunningRecord(Manager& man, float pay, 
	string Remarks, string payer , string collect )
	:Record(man)
{
	this->payment = pay;
	strcpy_s(this->remarks, Remarks.c_str());
	strcpy_s(this->payer, payer.c_str());
	strcpy_s(this->collectWay, collect.c_str());
}

RunningRecord::~RunningRecord(){}


RunningRecord::RunningRecord(const RunningRecord& obj) :Record(obj)
{
	this->payment = obj.payment;
	strcpy_s(this->remarks, obj.remarks);
	strcpy_s(this->payer, obj.payer);
	strcpy_s(this->collectWay, obj.collectWay);
}

RunningRecord RunningRecord:: operator= (const RunningRecord& obj) 

{
	Record::operator=(obj);
	this->payment = obj.payment;
	strcpy_s(this->remarks, obj.remarks);
	strcpy_s(this->payer, obj.payer);
	strcpy_s(this->collectWay, obj.collectWay);
	return *this;

}


void RunningRecord::display()
{
	string When = TimeStampToStandard(this->timeStamp);
	cout << "记录时间 :  " << When;
	cout << "开支费用 :  " << this->payment << endl;
	cout << "开支用途 :  " << this->remarks << endl;
	cout << "记录者   :  " << this->payer << endl;
	cout << "是否查看此次记录的管理员信息和支付方式？" << endl;
	if (checkToContinue()) 
	{
		cout << "支付方式 :  " << this->collectWay << endl;
		cout << "记录管理员信息的详细信息 :  " << endl;
		this->operatorManager.display();
	}

}


void RunningRecord::shortShow()
{
	string When = TimeStampToStandard(this->timeStamp);

	cout << setw(5)  << this->payment
		 << setw(15) << this->remarks
		 << setw(20) << When
		 << endl;
}