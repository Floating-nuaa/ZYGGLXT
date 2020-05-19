#ifndef  TRANSACTIONRECORD_H_
#define  TRANSACTIONRECORD_H_
#include "Record.h"
#include "Student.h"
#include "stdafx.h"
class TransactionRecord :public Record

	//交易记录类

{
protected:
	
	Student stud;    //学生对象信息
	float payment;	// 缴纳费用
	char collectWay[20]; // 收款方式
	char remarks[100]; //收款备注

public:
	
	//不能有无参构造函数

	TransactionRecord(Manager&, Student&, float pay=0,string CW="现金收款",string R="无");
	
	virtual ~TransactionRecord();
	
	TransactionRecord(const TransactionRecord&);
	
	virtual TransactionRecord operator =(const TransactionRecord&);

	void display();

	void shortShow();

	float getPayment();
};

#endif // ! TRANSACTIONRECORD_H_




