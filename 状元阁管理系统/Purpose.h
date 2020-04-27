#ifndef PURPOSE_H_
#define PURPOSE_H_
#include <string.h>
#include <iostream>
using namespace std;
class Purpose
{

private:
	char name;
public:
	Purpose(char );
	Purpose();
	char getName() { return name; }
	void display() { cout << name<<" "; }
};

#endif