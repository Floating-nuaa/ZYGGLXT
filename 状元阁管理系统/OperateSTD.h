#ifndef OPERATESTD_H_
#define OPERATESTD_H_

#include "OperateMode.h"
#include "PeoNum.h"
#include "STDInfo.h"
#include "Student.h"


class OperateSTD :public OperateMode 

	//刚开始我想把查询模块和增加模块分开的
	// 现在觉得这俩放一起挺好的
	//为了避免来回改名字，类名就不变了

{
private:

	void setStdsID( Student &);			//内置函数，声明成Student的友元函数
								//修改自己数据的ID，进行数据保护
protected:
	
	Student student;//学生对象
	STDInfo saveAddress;//文件地址对象
	
public:
	
	OperateSTD();
	~OperateSTD();

	void getInfoFromScreen();//把保护变量里的STD 填入信息

	bool saveThisFile();//保存文件

	bool readPreFile( );//从文件中读取文件信息
		
	Student getStudent();
	
};
#endif // !OperateSTD_H_
