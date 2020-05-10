#ifndef  TRANSACTIONRECORD_H_
#define  TRANSACTIONRECORD_H_
#include "Record.h"
#include "Student.h"

class TransactionRecord :public Record

	//交易记录类

{
protected:
	
	Student stud;
	float payment;
	char collectWay[20];
	char remarks[100];

public:
	
	//不能有无参构造函数
	TransactionRecord(Manager&, Student&, float pay=0,string CW="现金收款",string R="无");
	
	virtual ~TransactionRecord();
	
	TransactionRecord(const TransactionRecord&);
	
	virtual TransactionRecord operator =(const TransactionRecord&);

};

#endif // ! TRANSACTIONRECORD_H_
