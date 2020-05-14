#include "TableInfo.h"

TableInfo::TableInfo()
{
	//无参数构造测试文件名
	uniqueAddress = "TABInfo\\DataTable\\";
	fileName = "testStudent.txt";
	completeFile = saveAddress + uniqueAddress + fileName;
}

TableInfo::TableInfo(string Name)
{
	//含有参数构造文件名
	string temp = ".dat";

	string FM = Name + temp;
	uniqueAddress = "TABInfo\\DataTable\\";
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;

}

TableInfo TableInfo::operator=(const TableInfo& obj)
{
	//赋值号重载

	uniqueAddress = obj.saveAddress;	//功能文件夹
	fileName = obj.fileName;	//文件的名
	completeFile = obj.completeFile;	//完整文件路径
	
	return *this;

}



TableInfo::~TableInfo() 
{
	//析构函数，不需要什么参数
}

void TableInfo::setName(string name)
{
	string temp = ".dat";
	string FM = name + temp;
	//只修改了文件名
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;
}



void TableInfo::GiveTeacherALife()
	//为教师课表设置新的路径
{ 
	uniqueAddress = "TABInfo\\DataTable\\";
	completeFile = saveAddress + uniqueAddress + fileName;
}

void TableInfo::ForTeacherCSV(string name) 
{
	fileName = name + ".csv";
	uniqueAddress = "TABInfo\\VisionTable\\TEATable\\";
	completeFile = saveAddress + uniqueAddress + fileName;
}

void TableInfo::ForStudentCSV(string name) 
{
	fileName = name + ".csv";
	uniqueAddress = "TABInfo\\VisionTable\\STDTable\\";
	completeFile = saveAddress + uniqueAddress + fileName;
}
