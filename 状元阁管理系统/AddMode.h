#ifndef ADDMODE_H_
#define ADDMODE_H_
#include "BaseFile.h"
class AddMode 

	//增加Mode ，抽象类

{
private:
	
	//BaseFile *Bf;
	
	//基础文件的指针，可以指向基类和派生类
	//指向当前增加文件的或已有文件

public:
	
	AddMode();
	virtual ~AddMode();
	
	virtual void readPreFile();//读取前置文件
	virtual bool saveThisFile();//保存当前文件

};
#endif // !ADDMODE_H_

