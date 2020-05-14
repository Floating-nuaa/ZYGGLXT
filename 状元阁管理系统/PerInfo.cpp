#include "PerInfo.h"

PerInfo::PerInfo(string name)
{

	uniqueAddress = "PerInfo\\";
	string temp = ".dat";
	fileName = name + temp;
	completeFile = saveAddress + uniqueAddress + fileName;

}

PerInfo PerInfo::operator=(const PerInfo& obj)
{
	uniqueAddress = obj.saveAddress;//功能文件夹
	fileName = obj.fileName;//文件的名
	completeFile = obj.completeFile;//完整文件路径
	return *this;
}
PerInfo::~PerInfo() { }

void PerInfo::setName(string name)
{
	string temp = ".dat";
	fileName = name+temp;
	completeFile = saveAddress + uniqueAddress + fileName;
}

PerInfo::PerInfo(const PerInfo& obj)

{
	uniqueAddress = obj.saveAddress;//功能文件夹
	fileName = obj.fileName;//文件的名
	completeFile = obj.completeFile;//完整文件路径
}



