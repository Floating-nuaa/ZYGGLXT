#ifndef AddSTDMenu_H_
#define AddSTDMenu_H_
#include "Menu.h"
#include <iostream>
#include "Student.h"
using namespace std;

class AddSTDMenu :public Menu 

{
protected:
	
	Student student;

	Purpose catchPurpose();//获得科目

	void  catchAndAnylasis(int);//收集所有信息,创建一个学生并记录在成员变量里

	bool display2();//是否要定金和要求

public :
	
	//提供两个外部接口
	//选择输入方式，获得生成学生的对象
	
	AddSTDMenu(){}
	
	~AddSTDMenu() {}
	
	void display();//展示前几个信息,内部调用重要函数
	
	Student getStudent();

};
#endif // !AddSTDMenu_H_
