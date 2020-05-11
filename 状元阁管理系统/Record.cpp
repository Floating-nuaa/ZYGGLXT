#include "Record.h"


Record::~Record(){}



Record::Record(Manager &obj ):operatorManager(obj)
{
	//获得时间戳

	time_t now;
	int unixTime = (int)time(&now);
	this->timeStamp = unixTime;
}

Record::Record(const Record& obj)

{
	this->timeStamp = obj.timeStamp;
	this->operatorManager = obj.operatorManager;
}

Record Record::operator =(const Record& obj) 

{
	this->timeStamp = obj.timeStamp;
	this->operatorManager = obj.operatorManager;
	return *this;
}

int Record::getTimeStamp()
{
	return this->timeStamp;
}