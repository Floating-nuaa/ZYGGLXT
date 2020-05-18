#ifndef QUERYRECORD_H_
#define QUERYRECORD_H_
#include "RunningRecord.h"
#include "ViolationRecord.h"
#include "TransactionRecord.h"
#include "RecordInfo.h"


/*****************************************************


	这是查询课表的操纵台，只能被handler所调用

	能够查询收银记录，店内流水账，教师违规记录
	需要传入的参数是第几条记录
	返回这个类型的record
	注意收银记录有两条查询路线，第二条隐藏

	因为交易记录类型的类没有默认构造函数，所以需要创建一个临时的对象
	进行有参构造，当然这个记录是无意义的
	
	为了函数的简洁性，打开文件失败会抛出异常,要记得处理

******************************************************/

class QueryRecord 

{
protected:

	friend class Handler;			//只能通过友元类调用方法

	
	RunningRecord getRunningRecord(int ruler=1);
	ViolationRecord getViolationRecord(int ruler=1);
	TransactionRecord getTransactionRecord(int ruler=1);
	TransactionRecord getHidenTransactionRecord(int ruler = 1);

public :
	
	QueryRecord();
	~QueryRecord();

};

#endif // !QUERYRECORD_H_


