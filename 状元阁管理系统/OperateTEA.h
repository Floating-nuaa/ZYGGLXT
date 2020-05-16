#ifndef  OPERATETEA_H_
#define OPERATETEA_H_

#include "AddTEAMenu.h"
#include "TEAInfo.h"
#include "OperateMode.h"

class OperateTEA : public OperateMode 
{

private :
	//修改ID
	void setTeasID(People&);

protected:
	
	Teacher teacher;
	TEAInfo saveAddress;

public:

	OperateTEA();
	
	~OperateTEA();

	OperateTEA(const OperateTEA&);

	void getInfoFromScreen();//把保护变量里的TEA 填入信息

	bool saveThisFile();//保存文件

	bool readPreFile();//从文件中读取文件信息

	bool readPreFile(string name);

	Teacher getTeacher();

};
#endif // ! OPERATETEA_H_
