#pragma warning(disable : 4996)
#include <iostream>
#include "Date.h"
#include "OperateTable.h"
#include "FeasibleCmd.h"
#include "TollMenu.h"
#include "Manager.h"
#include "stdafx.h"
#include <time.h>
using namespace std;

int main() 

{
	FeasibleCmd FC;
	
	char name[20] = "panpan";
	char phone[30] = "15832513211";
	char ssh[20] = "123456";
	Manager ma(name, 'F', phone, ssh);
	TollMenu TM(ma);
	TM.display();
	return 0;

}

	