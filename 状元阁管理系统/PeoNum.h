#ifndef PEONUM_H_
#define PEONUM_H_

#include "BaseFile.h"

class PeoNum :public BaseFile 

{

protected:
	
	int NowNum;//当前数字

	bool setFile(int a=1);//设置此文件
	
	bool getNum();//取出文件内容

	void setNowNum(int);//更新当前的NowNum

	void update(int);//更新了ID数

public:
	
	//PeoNum( string UA = "PersonInfo\\", string FA = "PeoNum.txt");

	PeoNum();
	~PeoNum();
	int returnNum();

};
#endif // !PEONUM_H_

