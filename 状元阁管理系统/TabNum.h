#ifndef TABNUM_H_
#define TABNUM_H_
#include "BaseFile.h"

class TabNum :private BaseFile

{

protected:

	int NowNum;//当前数字

	bool setFile(int a = 1);//设置此文件

	bool getNum();//取出文件内容

	void setNowNum(int);//更新当前的NowNum

	void update(int);//更新了ID数

public:

	//TabNum( string UA = "PersonInfo\\", string FA = "TabNum.txt");

	TabNum();
	~TabNum();
	int returnNum();

};

#endif