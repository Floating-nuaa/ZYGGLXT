#ifndef ADDSTD_H_
#define ADDSTD_H_
#include "AddMode.h"
#include "Student.h"
#include "PeoNum.h"
#include "STDInfo.h"
class AddSTD :public AddMode 

{

protected:
	
	Student student;
	STDInfo saveAddress;

public:
	
	AddSTD();
	~AddSTD();

	void getInfo();//把保护变量里的STD 填入信息

	bool saveThisFile();//保存文件

};
#endif // !ADDSTD_H_
