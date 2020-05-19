/********************************************************************
	
			教师违规记录的类
	继承了Record 内置Unix时间戳和Manager
	记录了教学事故的记录
	发生时间，事故第一第二代码
	第一代码是教学事故的等级 
	第二代码是教学事故的具体事件
	由于记录可能有延后性，所以内置了Date类，进行发生时间的记录

*********************************************************************/
#ifndef VIOLATIONRECORD_H_
#define VIOLATIONRECORD_H_

#include "Date.h"
#include "Record.h"
#include "Teacher.h"

class ViolationRecord :public Record 
{
protected:
	
	Teacher VioTeacher;
	int FirstVioCode;
	int SecondCVioCode;
	Date OccurTime;
	char Remarks[100];//备注或者其他教学事故

public : 
	
	ViolationRecord(Manager&,Teacher &,int first,int second,Date d,string remark );
	~ViolationRecord();
	ViolationRecord(const ViolationRecord&);
	ViolationRecord operator =(const ViolationRecord&);
	void display();
};

#endif







