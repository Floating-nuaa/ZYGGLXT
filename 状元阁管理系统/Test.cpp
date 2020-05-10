#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Date.h"
#include "Table.h"
#include "PeoNum.h"
#include "OperateTable.h"
#include "FeasibleCmd.h"
#include "AddTEAMenu.h"
#include "OperateTEA.h"
using namespace std;



int main() 

{
	FeasibleCmd *FE;
	FE = new FeasibleCmd;
	delete FE;

	//OperateSTD OS;
	//OS.readPreFile();
	//ss = OS.getStudent();
	//OS.getInfoFromScreen();
	//OS.saveThisFile();
	//ss.display();
	//Student ss;
	
	OperateTable OT;
	
	OT.readPreFile();
	
	Table ttt = OT.getTable();
	
	ttt.display();

	return 0;
	
}