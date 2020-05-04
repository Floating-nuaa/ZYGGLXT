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
<<<<<<< HEAD

=======
#include "FatherTable.h"
#include "BaseFile.h"
#include "PremaryMenu.h"
>>>>>>> dev
using namespace std;

extern string welcome();

int main(){

<<<<<<< HEAD
	char name[29] = "laopan";
	People people(name);
	Date t1(2020, 7, 9);
	Date t2(2020, 7, 14);

	Table ttt(&people,t1, t2, 3);
	
	ttt.display();
=======
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

>>>>>>> dev
	return 0;

}