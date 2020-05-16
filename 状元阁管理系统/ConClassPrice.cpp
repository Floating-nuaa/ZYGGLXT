#include "ConClassPrice.h"
#include <iostream>
#include <fstream>
using namespace std;

ConClassPrice::ConClassPrice() :classPrice(1, 100, 60, "test")
{
	//构造函数，无需操作
}

ConClassPrice::~ConClassPrice() 
{
	//析构函数，无需操作
}

ConClassPrice::ConClassPrice(const ConClassPrice& obj):classPrice(obj.classPrice)
{
	//拷贝构造函数	
}

void ConClassPrice::getInfo(int type) 
{
	int inPrice, outPrice;
	string remark;

	cout << "现在输入第 " << type << " 类课程的信息" << endl;
	cout << "课程类型是" << translateNumToClassType(type) << endl;
	cout << "请输入收费标准 :  ";
	cin >> inPrice;	
	cout << "请输入工资标准 :  ";
	cin >> outPrice;
	cout << "请输入备注(没有填无) :  ";
	cin >> remark;
	this->classPrice.setClassPrice(type, inPrice, outPrice, remark);
	cout << endl;
}

bool ConClassPrice::initClassPrice() 
{

	ConfigInfo CF("ClassPrice");//产生文件储存路径
	
	ofstream file;

	file.open(CF.getCompleteAddress(), ios::out | ios::binary);//已经有了则刷新文件
	
	if (!file)
	{
		cout << "ClassPrice文件创建失败，请检查路径是否存在" << endl;
		cout << "当前路径 :  " << CF.getCompleteAddress();
	}
	
	system("CLS");
	
	cout << "************************************************************" << endl<<endl;
	cout << "友情提示  即将进行课程收支的初始化，请您准备好单据" << endl;
	cout << "友情提示  请注意周围环境是否合适且安全 ！" << endl;

	if (!checkToContinue()) 
	{
		operationCancled();
		return false;
	}
	
	for (int i = 1; i <= 6; i++)
	{
		getInfo(i);
		file.write((char*)&this->classPrice, sizeof(this->classPrice));
	}
	
	file.close();
	
	cout << "Success 课程费用标准创建成功" << endl;
	return true;
}

bool ConClassPrice::setClassPrice() 
{
	ConfigInfo CF("ClassPrice");//产生文件储存路径
	fstream file;
	
	file.open(CF.getCompleteAddress(),ios::out| ios::in | ios::binary);//已经有了则刷新文件
	
	if (!file)
	{
		cout << "ClassPrice文件打开失败，请检查路径是否存在" << endl;
		cout << "当前路径 :  " << CF.getCompleteAddress();
	}

	string type;

	for (int i = 1; i <= 6; i++)
	{
		type = translateNumToClassType(i);
		cout <<i<<". "<< type << endl;
	}
	
	cout << "请选择要修改课程类型的编号 :  ";
	int j=0;
	
	while (j <= 0 || j > 6) 
	{
		cin >> j;
	}
	
	file.read((char*)&this->classPrice, sizeof(this->classPrice));
	
	while (j != this->classPrice.getType()&&!file.eof())
	{
		file.read((char*)&this->classPrice, sizeof(this->classPrice));

	}
	
	if (j != this->classPrice.getType()) 
	{
		cout << "很遗憾  未查找到对应课程类型的Price信息 " << endl;
		file.close();
		return false;
	}
	
	else if (j == this->classPrice.getType()) 
	{
		getInfo(j);
	
		short t=(j-1)*sizeof(this->classPrice);
		
		file.seekp( t , ios::beg);
		file.write((char*)&this->classPrice, sizeof(this->classPrice));
		
		file.flush();
	}
	
	file.close();
	
	cout << "Success 课程费用标准修改成功" << endl;
	return true;
}

map<int, ClassPrice> ConClassPrice::getMapFromCon() 

{

	ConfigInfo CF("ClassPrice");//产生文件储存路径
	ifstream file;

	file.open(CF.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "ClassPrice文件打开失败，请检查路径是否存在" << endl;
		cout << "当前路径 :  " << CF.getCompleteAddress();
	}

	map<int, ClassPrice> MAP;    //生成课程代码与单价的map

	for (int i = 1; i <= 6; i++) 
	{
		file.read((char*)&this->classPrice, sizeof(this->classPrice));
		MAP.insert(pair<int, ClassPrice>(i, this->classPrice));
	}

	return MAP;

}

