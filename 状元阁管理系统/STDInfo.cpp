#include "STDInfo.h"
#include <string>

STDInfo::STDInfo() 
{
	uniqueAddress = "STDInfo\\";
	fileName = "testStudent.txt";
	completeFile = saveAddress + uniqueAddress + fileName;
}

STDInfo::STDInfo(string Name) 
{
	string temp = ".dat";
	string FM = Name + temp;
	uniqueAddress = "STDInfo\\";
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;

}

STDInfo STDInfo::operator=(const STDInfo& obj) 
{
	uniqueAddress=obj.saveAddress;//功能文件夹
	fileName=obj.fileName;//文件的名
	completeFile=obj.completeFile;//完整文件路径
	return *this;
}

STDInfo::~STDInfo(){ }

void STDInfo::setName(string name)
{
	//只改变文件名，不敢变储存位置

	string temp = ".dat";
	string FM = name + temp;
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;
}

STDInfo::STDInfo(const STDInfo& obj) 

{
	uniqueAddress = obj.saveAddress;//功能文件夹
	fileName = obj.fileName;//文件的名
	completeFile = obj.completeFile;//完整文件路径
}