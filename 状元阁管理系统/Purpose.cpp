#include "Purpose.h"
#include <string>

Purpose::Purpose(vector <string> a)

{
	for (vector<string>::iterator it = a.begin(); it != a.end(); it++) 
	{
		list.push_back(*it);
	}
}

Purpose::Purpose() 

{
	//无需操作
}
string Purpose::getList() 
{
	static vector<string>::iterator it = list.begin();
	return *it;
}

Purpose Purpose::operator=(const Purpose& obj)
{
	list = obj.list;
	return *this;
}

void Purpose::display() 
{
	cout << "科目： ";
	for (vector<string>::iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it<<" " ;
	}
	cout << endl;
}