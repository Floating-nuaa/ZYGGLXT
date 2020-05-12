#pragma warning(disable : 4996)
#include <iostream>
#include "Date.h"
#include "RelationMap.h"
#include "stdafx.h"
#include <time.h>
#include <fstream>
#include "FeasibleCmd.h"
#include "MainEntrance.h"
#include "LoginMenu.h"
using namespace std;

int main() 

{
	/*FeasibleCmd FC;
	
	char name[20] = "panpan";
	char phone[30] = "15832513211";
	char ssh[20] = "123456";
	
	Manager ma(name, 'F', phone, ssh);
	
	RunningMenu RM(ma);

	RM.display();
	*/

	MainEntrance ME;
	ME.ShowPre_Login();
	return 0;

}

	