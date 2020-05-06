#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "PeoNum.h"
#include "AddSTDMenu.h"
#include "AddSTD.h"
#include "FeasibleCmd.h"

using namespace std;



int main() {

	AddSTD AST;
	AST.getInfo();
	AST.saveThisFile();

	return 0;
}