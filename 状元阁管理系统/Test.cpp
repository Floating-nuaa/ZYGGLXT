#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "PeoNum.h"
#include "AddSTDMenu.h"
#include "People.h"
#include "FatherTable.h"
#include "BaseFile.h"
#include "MainMenu.h"
#include "PremaryMenu.h"
#include "FeasibleCmd.h"

using namespace std;



int main() {

	AddSTDMenu me;
	me.display();
	Student std;
	std = me.getStudent();
	std.display();
	return 0;
}