#include "AddSTD.h"
#include "Student.h"
#include "STDInfo.h"
#include <fstream>

using namespace std;


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
//这个没完成呢

bool AddSTD::saveThisFile() 
{
	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);
	
	if (!file) 
	
	{
		cout << "学生信息文件打开失败，请检查路径是否正确！" << endl;
		return 0;
	}
	
	file.write((char*)&student, sizeof(student));
	file.close();
	
	return 1;
}