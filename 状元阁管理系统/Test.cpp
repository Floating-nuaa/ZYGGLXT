#pragma warning(disable : 4996)
#include <iostream>
#include "Date.h"
#include "RelationMap.h"
#include "stdafx.h"
#include <time.h>
#include "Student.h"
#include <fstream>
#include "OperateTable.h"
#include "FeasibleCmd.h"
#include "AddTABMenu.h"
#include "OperateSTD.h"
using namespace std;

int main() 

{
	FeasibleCmd FC;

	//OperateSTD OS;
	//OS.getInfoFromScreen();
	//OS.saveThisFile();
	Table T;
	AddTABMenu AT;
	AT.display();
	T = AT.getTable();
	T.displaySTD();
	return 0;
}
