#include "TransactionRecord.h"

TransactionRecord::TransactionRecord
	(Manager& man, Student& stu, float pay , string CW , string R )
	:Record(man),stud(stu)

{
	this->payment = pay;
	strcpy_s(this->collectWay, CW.c_str());
	strcpy_s(this->remarks, R.c_str());
}

TransactionRecord::~TransactionRecord(){}

TransactionRecord::TransactionRecord(const TransactionRecord& obj):Record(obj)

{
	this->payment = obj.payment;
	strcpy_s(this->collectWay, obj.collectWay);
	strcpy_s(this->remarks, obj.remarks);
}

TransactionRecord TransactionRecord::operator=(const TransactionRecord& obj)

{
	Record::operator=(obj);

	this->payment = obj.payment;
	strcpy_s(this->collectWay, obj.collectWay);
	strcpy_s(this->remarks, obj.remarks);
	return *this;
}