#ifndef ADDSTD_H_
#define ADDSTD_H_
#include "AddMode.h"
#include "Student.h"
#include "PeoNum.h"
#include "STDInfo.h"

class AddSTD :public AddMode 

	//刚开始我想把查询模块和增加模块分开的
	// 现在觉得这俩放一起挺好的
	//为了避免来回改名字，类名就不变了

{
private:
	//void setStdsID(); //内置函数，声明成student的友元函数
protected:
	
	Student student;//学生对象
	STDInfo saveAddress;//文件地址对象
	
public:
	
	AddSTD();
	~AddSTD();

	void getInfo();//把保护变量里的STD 填入信息

	bool saveThisFile();//保存文件

	bool readInfo(string);

	void diaplay();
};
#endif // !ADDSTD_H_
