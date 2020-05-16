#ifndef CONCLASSPRICE_H_
#define CONCLASSPRICE_H_
#include "ClassPrice.h"
#include "ConfigInfo.h"
#include "stdafx.h"
#include <fstream>
#include <map>
/****************************************************************
			对课程单价进行增添和修改的类
		增加是初始化的时候进行调用，修改是读取并进行修改
		用一个读取函数进行检验
*****************************************************************/


class ConClassPrice 
{
protected:

	ClassPrice classPrice;
	void getInfo(int type);

public:

	ConClassPrice();
	~ConClassPrice();
	ConClassPrice(const ConClassPrice&);
	bool initClassPrice();
	bool setClassPrice();
	map<int ,ClassPrice> getMapFromCon();//返回一个课程类型到单价的map

};


#endif // !CONCLASSPRICE_H_


