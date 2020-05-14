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
		cout << "当前路径:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}
	
	file.close();

	objTab.ReviseTeam();

	ST2.setOtherName(objTab.getOwnerName());
	ST2.buildStoreTable(objTab);
	
	string str = objTab.getOwnerName();
	
	this->saveAddress.setName(str);
	this->saveAddress.GiveTeacherALife();

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
		cout << "当前路径:  " << this->saveAddress.getCompleteAddress() << endl;
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

		file.close();

		this->table.translateFromStoreTable(ST);
	}
	catch (int goal)
	{
		cout << "错误代码： " << goal << "  ";
		cout << "课表文件打开失败，请检查路径是否非法！" << endl;
		cout << "当前路径:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}

	
	
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

		file.close();

		this->table.translateFromStoreTable(ST);
	}
	catch (int goal)
	{
		cout << "错误代码： " << goal << "  ";
		cout << "课表文件打开失败，请检查路径是否非法！" << endl;
		cout << "当前路径:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}


	return 1;

}

//把Table转换为.csv 文件，只限于当前对象
bool OperateTable::transformSTToCSV() 

{

	saveAddress.ForStudentCSV(this->table.getOwnerName());
	
	ofstream file;
	try {
		file.open(this->saveAddress.getCompleteAddress(), ios::out | ios::app);

		if (!file)
		{
			throw 987;
		}
		file  <<this->table.getSelfName()<<endl;
		file << translateNumToClassType(table.getClassType()) << endl;

		while (!table.lessonTimeTable.empty())

			//循环拿出优先队列中的课程

		{

			Lesson lesson(table.lessonTimeTable.top());

			file<<lesson.getMonth();
			file << ".";
			file << lesson.getDay();
			file << ",";
			table.lessonTimeTable.pop();

		}
		file << "\n";
		for (int i = 1; i <= table.getNum(); i++) 
		{
			file << table.getTheOtherName() << ",";
		}
		file << "\n\n";
		file.close();
	}
	catch (int goal) 
	{
		cout << "错误代码： " << goal << "  ";
		cout << "课表文件打开失败，请检查路径是否非法！" << endl;
		cout << "当前路径:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}
	return 1;

}



bool OperateTable::transformTTToCSV()

{

	saveAddress.ForTeacherCSV(this->table.getOwnerName());

	ofstream file;
	try {
		file.open(this->saveAddress.getCompleteAddress(), ios::out | ios::app);

		if (!file)
		{
			throw 987;
		}
		file << this->table.getSelfName() << endl;
		file << translateNumToClassType(table.getClassType()) << endl;

		while (!table.lessonTimeTable.empty())

			//循环拿出优先队列中的课程

		{

			Lesson lesson(table.lessonTimeTable.top());

			file << lesson.getMonth();
			file << ".";
			file << lesson.getDay();
			file << ",";
			table.lessonTimeTable.pop();

		}
		file << "\n";
		for (int i = 1; i <= table.getNum(); i++)
		{
			file << table.getTheOtherName() << ",";
		}
		file << "\n\n";
		file.close();
	}
	catch (int goal)
	{
		cout << "错误代码： " << goal << "  ";
		cout << "课表文件打开失败，请检查路径是否非法！" << endl;
		cout << "当前路径:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}

	return 1;
}



