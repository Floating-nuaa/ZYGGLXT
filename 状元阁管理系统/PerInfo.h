#ifndef PERINFO_H_
#define PERINFO_H_
#include "STDInfo.h"
class PerInfo :public STDInfo 


{
private:

	void setName(string Name);

public:

	PerInfo( );

	PerInfo( );

	virtual ~PerInfo();

	PerInfo operator = (const PerInfo &);

};

#endif // !PERINFO_H_

