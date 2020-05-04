#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "People.h"
#include "DEFINE.cpp"
#include "Purpose.h"
#include "Student.h"
#include "Teacher.h"
#include "stdafx.h"
#include "Lesson.h"
#include "FatherTable.h"
#include "BaseFile.h"
#include "PremaryMenu.h"
using namespace std;

extern string welcome();

int main(){

	/*Date d1(2020, 7, 8);
	char name[29] = "laopan";
	People people(name);
	FatherTable f(&people);
	Table t(&people,d1,3,4);
	f.display();
	t.display();
	BaseFile BF;
	BF.display();
	BF.changeSaveAddress();
	BaseFile AF;
	AF.display();*/

	Menu* PpppR;
	PpppR = new PremaryMenu;
	PpppR->display();
	delete PpppR;
	PpppR = NULL;

	return 0;

}