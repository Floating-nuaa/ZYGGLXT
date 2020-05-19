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
	
	void getChangeInfo();
	bool catchElection();
	bool doChangeInfo(int election);
	Purpose catchPurpose();

public:

	OperateTEA();
	
	~OperateTEA();

	OperateTEA(const OperateTEA&);

	void getInfoFromScreen();//把保护变量里的TEA 填入信息

	bool saveThisFile();//保存文件

	bool readPreFile();//从私人文件中读取文件信息

	bool readPreFile(string name);

	bool readPreFile(int oridinal);//从教师总表中获取第几个老师的信息
	
	Teacher getTeacher();

	bool updateTeacherInfo(string STDname);


};
#endif // ! OPERATETEA_H_



