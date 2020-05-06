#ifndef PURPOSE_H_
#define PURPOSE_H_
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Purpose

{

private:

	vector<string> list;//是一个string向量表，内置了科目

public:
	
	Purpose( vector <string>  );
	Purpose();

	string getList();
	void display();

	Purpose operator=(const Purpose&);
};

#endif