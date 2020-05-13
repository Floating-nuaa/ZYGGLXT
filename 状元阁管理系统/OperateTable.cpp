#include "OperateTable.h"
#include "Table.h"
#include "StoreTable.h"
#include <fstream>

using namespace std;



OperateTable::~OperateTable()
{
	//析构函数，无需操作
}

OperateTable::OperateTable() :table(),saveAddress()

{
	//无参构造，无需操作
}

OperateTable::OperateTable ( Table &tab ) : table( tab )

{
	//获得所有者的姓名，对储存地址进行初始化、

	string str=tab.getOwnerName();
	

	this->saveAddress.setName(str);

}

Table OperateTable::getTable()
{
	return this->table;
}

bool OperateTable::saveThisFile() 
{
	Table objTab(this->table);
	fstream file;
	StoreTable ST1,ST2;

	ST1.buildStoreTable(this->table);

	try {
		file.open(saveAddress.getCompleteAddress(), ios::out | ios::binary);
		if (!file)
		{
			//打开文件失败，抛出异常

			throw 978;
		}
		file.write((char*)&ST1, sizeof(ST1));
		file.flush();
	}
	catch (int goal) 
	{
		cout << "错误代码： " << goal<<"  ";
		cout << "学生课表文件保存失败，请检查路径是否非法！" << endl;
		return 0;
	}
	
	file.close();

	objTab.ReviseTeam();

	ST2.setOtherName(objTab.getOwnerName());
	ST2.buildStoreTable(objTab);
	string str = objTab.getOwnerName();
	
	this->saveAddress.setName(str);

	try {
		file.open(saveAddress.getCompleteAddress(), ios::out | ios::binary);
		if (!file)
		{
			//打开文件失败，抛出异常

			throw 978;
		}
		file.write((char*)&ST2, sizeof(ST2));
		file.flush();
	}
	catch (int goal)
	{
		cout << "错误代码： " << goal << "  ";
		cout << "教师课表文件保存失败，请检查路径是否非法！" << endl;
		return 0;
	}
	file.close();

	return 1;

}

bool OperateTable::readPreFile() 

	//读入配置文件，对这个类的对象进行赋值

{
	string thisName = "test";
	cout << "\t请输入要查询学生的姓名:  ";
	cin >> thisName;
	cout << endl;
	saveAddress.setName(thisName);

	StoreTable ST;
	fstream file;
	
	try {
		file.open(saveAddress.getCompleteAddress(), ios::in | ios::binary);
		if (!file)
		{
			//打开文件失败，抛出异常

			throw 987;
		}

		file.read((char*)&ST, sizeof(ST));

		file.flush();
	}
	catch (int goal)
	{
		cout << "错误代码： " << goal << "  ";
		cout << "课表文件打开失败，请检查路径是否非法！" << endl;
		return 0;
	}

	file.close();

	this->table.translateFromStoreTable(ST);
	
	return 1;

}

bool OperateTable::readPreFile(string name)

//读入配置文件，对这个类的对象进行赋值

{
	string thisName = name;
	saveAddress.setName(thisName);

	StoreTable ST;
	fstream file;

	try {
		file.open(saveAddress.getCompleteAddress(), ios::in | ios::binary);
		if (!file)
		{
			//打开文件失败，抛出异常

			throw 987;
		}
		
		file.read((char*)&ST, sizeof(ST));
		
		file.flush();
	}
	catch (int goal)
	{
		cout << "错误代码： " << goal << "  ";
		cout << "课表文件打开失败，请检查路径是否非法！" << endl;
		return 0;
	}

	file.close();

	this->table.translateFromStoreTable(ST);

	return 1;

}


