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
	Table T;

	/*AddTABMenu AT;
	AT.display();
	T = AT.getTable();
	OperateTable OT(T);
	OT.saveThisFile();
	*/
	OperateTable OT,OT1;
	OT.updateThisTable();
	OT.readPreFile("≈Àº—ª‘");
	T = OT.getTable();
	T.displaySTD();
	OT1.readPreFile("–°∑…");
	T = OT1.getTable();
	T.displayTEA();
}






