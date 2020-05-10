#ifndef OPERATEMODE_H_
#define OPERATEMODE_H_
#include "BaseFile.h"



class OperateMode 

	//OperateMode ，抽象类
	//刚开始我想把查询模块和增加模块分开的
	// 现在觉得这俩放一起挺好
{

public:
	
	virtual bool readPreFile() = 0;//读取前置文件
	virtual bool saveThisFile() = 0;//保存当前文件
	
	OperateMode(){}
	virtual ~OperateMode(){}
	
};
#endif // !OperateMode_H_


