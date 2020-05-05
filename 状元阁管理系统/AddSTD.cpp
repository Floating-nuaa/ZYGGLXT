#include "AddSTD.h"
#include "Student.h"
#include "STDInfo.h"
#include "AddSTDMenu.h"
AddSTD::AddSTD() {}

AddSTD::~AddSTD(){}

void AddSTD::getInfo() 

//把保护变量里的STD 填入信息

{
	AddSTDMenu  ASM;
	ASM.display();
	student =  ASM.getStudent();
	string name(student.getName());

	STDInfo SI(name);
	saveAddress = SI;
}
//记着这个没完成呢
bool saveThisFile() 
{

}