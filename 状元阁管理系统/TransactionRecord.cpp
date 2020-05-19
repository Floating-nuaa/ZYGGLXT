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

TransactionRecord::TransactionRecord(const TransactionRecord& obj):Record(obj),stud(obj.stud)

{
	this->payment = obj.payment;
	strcpy_s(this->collectWay, obj.collectWay);
	strcpy_s(this->remarks, obj.remarks);
}

TransactionRecord TransactionRecord::operator=(const TransactionRecord& obj)

{
	Record::operator=(obj);
	this->stud = obj.stud;
	this->payment = obj.payment;
	strcpy_s(this->collectWay, obj.collectWay);
	strcpy_s(this->remarks, obj.remarks);
	return *this;
}

void TransactionRecord::display()
{
	string When = TimeStampToStandard(this->timeStamp);
	cout << "交易时间 :  " << When << endl;
	cout << "学生     :  " << stud.getName() << endl;
	cout << "交易金额 :  " << this->payment << endl;
	cout << "收款方式 :  " << this->collectWay << endl;
	cout << "收款备注 :  " << this->remarks << endl;
	cout << "是否显示此次交易人的详细信息?" << endl;

	if (checkToContinue()) 
	{
		cout << "此次交易学生的详细信息如下:  " << endl;
		this->stud.display();
		cout << "此次交易的管理员的信息如下:  " << endl;
		this->operatorManager.display();
		cout << endl;
	}
	return;
}

void TransactionRecord::shortShow()
//输出一行
{
	string When = TimeStampToStandard(this->timeStamp);
	cout << setw(5)  << stud.getName()
		 << setw(6)  << this->payment
		 << setw(20) << When
		 << endl;
}




float TransactionRecord::getPayment()
{
	return this->payment;
}
