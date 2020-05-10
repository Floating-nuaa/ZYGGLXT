#ifndef PERINFO_H_
#define PERINFO_H_
#include "STDInfo.h"

class PerInfo :public STDInfo


{
public:
	
	void setName(string Name);

	PerInfo( );

	PerInfo(const PerInfo&);

	virtual ~PerInfo();

	PerInfo operator = (const PerInfo &);

};

#endif // !PERINFO_H_

