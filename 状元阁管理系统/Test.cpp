#pragma warning(disable : 4996)
#include <iostream>
#include "Date.h"
#include "RelationMap.h"
#include "stdafx.h"
#include <time.h>
#include "Student.h"
#include <fstream>
#include "OperateTable.h"
#include "RegisterManagerMenu.h"
#include "FeasibleCmd.h"
#include "AddTABMenu.h"
#include "OperateSTD.h"
#include "ViolationMenu.h"
#include "ConClassPrice.h"
using namespace std;

int main() 

{
	OperateTEA OT,OT1;
	Teacher T,T1;
	/*OT.getInfoFromScreen();
	OT.saveThisFile();
	OT.getInfoFromScreen();
	OT.saveThisFile();*/
	OT.getInfoFromScreen();
	OT.saveThisFile();
	OT.readPreFile(3);
	T = OT.getTeacher();
	T.display();
	return 0;

}






