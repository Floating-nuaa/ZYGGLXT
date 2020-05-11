#ifndef  RECORD_H_
#define RECORD_H_
#include "Manager.h"
#include <time.h>

/************************************************************************

	记录类，生成各种记录，
	包括

		1.学费收银记录
		2.增添人员记录
		3.店内流水记录
		4.支付工资记录

**************************************************************************/

class Record

{
protected:

	Manager operatorManager;		//操作者
	int timeStamp;					//系统时间戳，记录操作时的时间


public:

	//只能含参构造，不能缺省，因为操作人员不明确会出问题
	
	Record(Manager &) ;

	virtual ~Record() ;

	Record(const Record&);

	virtual Record operator =(const Record&);

	virtual int getTimeStamp();

};


#endif // ! RECORD_H_
