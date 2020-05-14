#ifndef PERINFO_H_
#define PERINFO_H_
#include "STDInfo.h"

/*人员总信息储存类，必须传入string进行初始化*/

class PerInfo :public STDInfo
{
public:
	
	PerInfo( string name);
	
	virtual ~PerInfo();

	PerInfo(const PerInfo&);

	PerInfo operator = (const PerInfo &);

	void setName(string Name);
};

#endif // !PERINFO_H_

