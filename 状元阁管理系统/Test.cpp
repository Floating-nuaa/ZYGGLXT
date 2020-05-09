#include <iostream>
#include <string>
#include <vector>
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
	FeasibleCmd *FE;
	FE = new FeasibleCmd;
	delete FE;

	OperateSTD OS;
	
	Student ss;
	
	//OS.getInfoFromScreen();
	//OS.saveThisFile();
	
	OS.readPreFile();
	ss=OS.getStudent();

	ss.display();
	return 0;

}