#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "PeoNum.h"
#include "AddSTDMenu.h"
#include "OperateSTD.h"
#include "FeasibleCmd.h"
#include "AddTEAMenu.h"
#include "OperateTEA.h"
using namespace std;



int main() 

{
	OperateTEA OT,OA;
	
	Teacher TE;
	
	OT.getInfoFromScreen();
	OT.saveThisFile();

	OA.readPreFile();
	TE=OA.getTeacher();
	
	TE.display();

	return 0;
}