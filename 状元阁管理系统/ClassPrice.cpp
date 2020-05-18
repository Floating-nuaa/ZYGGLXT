#include "ClassPrice.h"

ClassPrice::ClassPrice(int classTC, int IP, int OP, string remark) 
{
	this->classTypeCode = classTC;
	this->inPrice = IP;
	this->outPrice = OP;
	strcpy_s(this->Remarks, remark.c_str());
}

ClassPrice:: ~ClassPrice()
{
	//析构函数，无需操作
}

void ClassPrice::updateCP(int IP, int OP, string remark)
{
	//课程的代码不能变，变了会出错的
	this->inPrice = IP;
	this->outPrice = OP;
	strcpy_s(this->Remarks, remark.c_str());
}




void ClassPrice::setClassPrice(int classTC, int IP, int OP, string remark) 
{
	this->classTypeCode = classTC;
	this->inPrice = IP;
	this->outPrice = OP;
	strcpy_s(this->Remarks, remark.c_str());
}

int ClassPrice::getType() 
{
	return this->classTypeCode;
}


int ClassPrice::getInPrice() 
{
	return this->inPrice;
}


int ClassPrice::getOutPrice()
{
	return this->outPrice;
}