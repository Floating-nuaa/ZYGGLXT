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

	char subject[7][10];
	int sum;

	//把vector存车的方式改成了string数组和记录数量的变量

public:
	
	Purpose( vector <string>  );//含参数构造
	
	Purpose();//无参数构造
	
	Purpose(const Purpose& obj);//拷贝构造
	

	~Purpose();//析构
	


	void display();



	Purpose operator=(const Purpose&);


};

#endif