#include "PerInfo.h"

PerInfo::PerInfo()
{
	string temp = "AllPerson.dat";
	string FM = temp;
	uniqueAddress = "PerInfo\\";
	fileName = FM;
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
	string temp = "AllPerson.dat";
	fileName = temp;
	completeFile = saveAddress + uniqueAddress + fileName;
}

PerInfo::PerInfo(const PerInfo& obj)

{
	uniqueAddress = obj.saveAddress;//功能文件夹
	fileName = obj.fileName;//文件的名
	completeFile = obj.completeFile;//完整文件路径
}