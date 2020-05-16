#ifndef CONFIGINFO_H_
#define CONFIGINFO_H_
#include "STDInfo.h"
/***************************************************************
		配置文件的储存位置
	需要的配置文件有如下几个
	ClassPrice
****************************************************************/

class ConfigInfo : public STDInfo

{

public:
	ConfigInfo(string Name);

	ConfigInfo();

	virtual ~ConfigInfo();

	ConfigInfo operator = (const ConfigInfo&);


};
#endif
