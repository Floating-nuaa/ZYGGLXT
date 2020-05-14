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
	
	ofstream file;
	file.open("E://VisualStudio//Data//ttttt.csv", ios::out);
	for (int i = 1; i <= 100; i++) 
	{
		for (int j = 1; j <= 100; j++) {
			file << i * j << ",";
		}
		file << endl;
	}
	file.close();
	return 0;
}

	