#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "People.h"
#include "DEFINE.cpp"
#include "Purpose.h"
#include "Student.h"
#include "Teacher.h"
#include "stdafx.h"
#include "Lesson.h"

using namespace std;

extern string welcome();

int main(){

	char name[29] = "laopan";
	People people(name);
	Date t1(2020, 7, 9);
	Date t2(2020, 7, 14);

	Table ttt(&people,t1, t2, 3);
	
	ttt.display();
	return 0;

}