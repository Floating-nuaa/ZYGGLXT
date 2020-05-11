#include "RunningRecord.h"

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
}

