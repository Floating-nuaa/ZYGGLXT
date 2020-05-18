#include "ViolationRecord.h"



ViolationRecord::ViolationRecord(Manager& obj,Teacher& tea ,
	int first, int second, Date d, string remark)
	:Record(obj),OccurTime(d),VioTeacher(tea)
{

	this->FirstVioCode = first;
	this->SecondCVioCode = second;
	strcpy_s(this->Remarks, remark.c_str());

}

ViolationRecord::ViolationRecord(const ViolationRecord& obj) 
	:Record(obj),OccurTime(obj.OccurTime),VioTeacher(obj.VioTeacher)
{
	this->FirstVioCode = obj.FirstVioCode;
	this->SecondCVioCode = obj.SecondCVioCode;
	strcpy_s(this->Remarks, obj.Remarks);
}


ViolationRecord:: ~ViolationRecord()
{
	//析构函数，无需操作
}



ViolationRecord ViolationRecord::operator =(const ViolationRecord& obj)


{
	Record::operator=(obj);
	this->VioTeacher = obj.VioTeacher;
	this->OccurTime = obj.OccurTime;
	this->FirstVioCode = obj.FirstVioCode;
	this->SecondCVioCode = obj.SecondCVioCode;
	return *this;
}

void ViolationRecord::display() 
{
	string What = trnaslateVioCode(this->FirstVioCode, this->SecondCVioCode);
	string When = TimeStampToStandard(this->timeStamp);
	cout << "教学事故记录生成时间" << When << endl;
	cout << "教师姓名 :  " << this->VioTeacher.getName() << endl;
	cout << "发生时间 :  ";
	this->OccurTime.display();
	cout << endl;
	
	cout << "教学事故 :  " << What << endl;
	cout << "事故备注 ： " << this->Remarks << endl;
	cout << "是否查询教师个人信息或记录管理员信息" << endl;
	if (checkToContinue())
	{
		cout << "当前教师信息如下:  " << endl;
		this->VioTeacher.display();
		cout << "生成记录管理员信息如下 :  " << endl;
		this->operatorManager.display();

	}
	return;
}



