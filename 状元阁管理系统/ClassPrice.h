#ifndef CLASSPRICE_H_
#define CLASSPRICE_H_
#include <string>
using namespace std;
/***************************************************************************
			这是一个简单的数据类
		负责记录课程类型的收入单价和发放单价
		注意也要对应课程的类型
****************************************************************************/
class ClassPrice 
{

private:

	int classTypeCode;				//课程类型的代码
	int inPrice;					//从学生处收取
	int outPrice;					//发放给教师
	char Remarks[20];

public:
	
	ClassPrice(int classTC,int IP,int OP,string remark);
	~ClassPrice();
	
	void updateCP(int IP, int OP, string remark);				//读取出来后进行修改
	void setClassPrice(int classTC, int IP, int OP, string remark);
	
	int getType();
	int getInPrice();
	int getOutPrice();

};
#endif