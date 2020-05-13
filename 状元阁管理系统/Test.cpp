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
using namespace std;

int main() 

{
	FeasibleCmd FC;
	
	char name[20] = "panpan";
	char phone[30] = "15832513211";
	char ssh[20] = "123456";
	Purpose P;
	Student ma(name,P );
	char na[15] = "¿œ≈÷";
	Date d1(2020, 1, 5), d2(2020, 1, 10);
	Table T1(&ma,d1,d2,3,na),T2,T3;

	OperateTable OT1(T1),OT2,OT3;
	OT1.saveThisFile();
	
	OT2.readPreFile("panpan");
	T2=OT2.getTable();
	T2.displaySTD();

	system("pause");
	OT3.readPreFile("¿œ≈÷");
	T3 = OT3.getTable();
	T3.displayTEA();
	
	return 0;
}

	