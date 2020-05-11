#ifndef RECORDINFO_H_
#define RECORDINFO_H_
#include "STDInfo.h"
class RecordInfo : public  STDInfo
/*************************************************************
	
	交易类文件的储存地址，以为涉及到交易，所以信息比较重要
	实现传参命名的功能
	最后修改时间 2020/5/11
**************************************************************/

{
public :

	RecordInfo(string Name);

	RecordInfo();

	virtual ~RecordInfo();

	RecordInfo operator = (const RecordInfo&);

};


#endif // !RECORDINFO_H_

