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
		file.open(saveAddress.getCompleteAddress(), ios::out | ios::binary|ios::app);
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

bool OperateTable::saveThisFile(int ruler) //调用这个的是教师的课表，教师名字在前

{
	Table objTab(this->table);

	fstream file;

	StoreTable ST1, ST2;

	ST1.buildStoreTable(this->table);

	try {
		file.open(saveAddress.getCompleteAddress(), ios::out | ios::binary | ios::in);
		if (!file)
		{
			//打开文件失败，抛出异常

			throw 978;
		}
		short t = (ruler - 1) * sizeof(ST1);
		file.seekp(t, ios::beg);
		file.write((char*)&ST1, sizeof(ST1));
		file.flush();
	}
	catch (int goal)
	{
		cout << "错误代码： " << goal << "  ";
		cout << "教师课表文件变更失败，请检查路径是否非法！" << endl;
		cout << "当前路径:  " << this->saveAddress.getCompleteAddress() << endl;
		return 0;
	}

	file.close();

	int howLong;
	howLong = checkHowLongBelonging(objTab);		//现在里边是教师课表
	short tt = (howLong - 1) * sizeof(ST1);			

	objTab.ReviseTeam();

	ST2.setOtherName(objTab.getOwnerName());

	ST2.buildStoreTable(objTab);

	string str = objTab.getOwnerName();

	this->saveAddress.setName(str);
	
	this->saveAddress.GiveTeacherALife();

	try {
		file.open(saveAddress.getCompleteAddress(), ios::out | ios::binary|ios::in);
		
		if (!file)
		{
			//打开文件失败，抛出异常

			throw 978;
		}
		file.seekp(tt, ios::beg);
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

bool OperateTable::readPreFile(string name, int oridinal) 
//oridinal 代表第几个数据
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
		short t = (oridinal-1) * sizeof(this->table);
		
		file.seekg(t, ios::beg);
		/*************************************************************
			重载要点，调整读取指针
		**************************************************************/

		file.read((char*)&ST, sizeof(ST));
		if (file.eof())
		{
			return false;
		}
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
	return true;
}


/**************************************************************************
//把Table转换为.csv 文件，只限于当前对象
	第一个是转换学生课表，第二个转换教师课表，储存路径不同
***************************************************************************/


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



bool OperateTable::updateThisTable()
{
	system("cls");
	string TEAName;
	int cnt = 1;
	cout << "*************************************************************" << endl;
	cout << "\t修\t改\t课\t表" << endl<<endl;
	cout << "请输入教师姓名 :  ";
	cin >> TEAName;
	bool flag;
	while (readPreFile(TEAName,cnt))
	{
		
		this->table.shortShowSTD();
		if (!checkIsThisTable()) 
		{
			
			cout << endl;
			continue;
		}
		if (changeThisTable())			//课表变更
		{
			flag = 1;
			
			saveThisFile(cnt);					//保存变更
			
			cout << "是否修改此位老师的其他课表？" << endl;
			if (!checkToContinue())
			{
				operationCancled();
				return true;
			}
		}
		cnt++;
	}
	if (!flag) 
	{
		return false;
	}
	return true;
}


bool OperateTable::checkIsThisTable()
{
	this->table.shortShowTEA();
	int temp=0,temp2=0;
	
	while (temp <= 0 || temp > 3) 
	{
		cout << "1. 修改此课表  2. 展示此课表详细信息  3. 展示下一个课表 " << endl;
		cout << "请选择要使用的功能 :  ";
		cin >> temp;
	}
	switch (temp) 
	{
		case 1: 
		{
			return true;
			break;
		}
		case 2: 
		{
			Table show(this->table);
			show.displayTEA();
			
			while (temp2 <= 0 || temp2 > 2)
			{
				cout << "1. 修改此课表  2. 展示下一个课表 " << endl;
				cout << "请选择要使用的功能 :  ";
				cin >> temp2;
			}
			if (temp2 == 1)
			{
				return true;
			}
			else if (temp2 == 2)
			{
				return false;
			}
			else 
			{
				return false;
			}
			break;
		}
		case 3:
		{
			return false;
			break;
		}
		default: 
		{
			return false;
			break;
		}
	}
}



bool OperateTable::changeThisTable()
{
	system("cls");
	
	Table show(this->table);
	show.displayTEA();
	cout << endl << endl;
	
	int temp = 0;
	
	while (temp <= 0 || temp > 3)
	{
		cout << "1. 增加课程 2. 删减课程 3. 调整课程时间 4. 调整课程类型"<<endl;
		cout << "请选择要使用的功能 :  ";
		cin >> temp;
	}
	cout << "您选择的是 " << temp << " 功能" << endl;
	if (!checkToContinue())
	{
		operationCancled();
		return false;
	}
	switch (temp) 
	{
		case 1:
		{
			
			do 
			{
				if (addLesson())
				{
					cout << "Success 添加成功" << endl;
				}
				else 
				{
					cout << "课程添加失败 !" << endl;
				}
			} while (checkToContinue());

			break;

		}
		case 2:
		{
			
			do 
			{
				if (!deleteLesson())
				{
					cout << "删除课程失败，可能是由于输入的日期信息和课程序数不对应导致的" << endl;
					cout << "请您检查后再进行修改" << endl;
				}
				else 
				{
					cout << endl;
				}
			} while (checkToContinue());

			break;
		}
		case 3:
		{
			do
			{
				cout << "请输入变更前的课程信息  " << endl;
				if (!deleteLesson()) 
				{
					cout << "删除课程失败，可能是由于输入的日期信息和课程序数不对应导致的" << endl;
					cout << "请您检查后再进行修改" << endl;
				}
				cout << "请输入变更后的课程信息  " << endl;

				if (!addLesson())
				{
					cout << "课程信息变更成功 !" << endl;
				}
			
			} while (checkToContinue());

			break;
		}
		case 4: 
		{
			int type=0;
			cout << "当前的课程类型是 " << translateNumToClassType(this->table.classType) << endl;
			if (!checkToContinue())
			{
				operationCancled();
				return false;
			}
			do
			{
				for (int i = 1; i <= 6; i++)
				{
					cout << i << ". " << translateNumToClassType(i) << endl;
				}

				cout << "请输入新的课程类型的对应编号(1-6)  " << endl;

			} while (type <= 0 || type > 6);

			this->table.classType = type;
			break;
		}
		default: 
		{
			cout << "Warning 选项代码异常！！！" << endl;
		}
	}
	return true;
}

bool OperateTable::addLesson()
{
	int month = 1, day = 1, num = 1;
	cout << "请输入月份	     :  ";
	cin >> month;
	cout << "请输入日期      :  ";
	cin >> day;
	cout << "请输入第几节课  :  ";
	Lesson lesson(month, day, num);
	this->table.lessonTimeTable.push(lesson);
	this->table.number++;
	return true;
}


bool OperateTable::deleteLesson()
{
	
	
	int month = 1, day = 1, num = 1;
	cout << "请输入月份	     :  ";
	cin >> month;
	cout << "请输入日期      :  ";
	cin >> day;
	cout << "请输入第几节课  :  ";

	Lesson lesson(month, day, num), tem;

	int j = this->table.getNum();

	while (j && this->table.lessonTimeTable.top() != lesson && !this->table.lessonTimeTable.empty())
	{

		tem = this->table.lessonTimeTable.top();
		this->table.lessonTimeTable.pop();
		this->table.lessonTimeTable.push(tem);
		j--;

	}
	
	if (!j)
	{
		return false;
	}
	else
	{
		cout << "课程删除成功! 删除的课程信息如下 : " << endl;
		lesson.display();
		return true;
	}

}


int OperateTable::checkHowLongBelonging(Table TEATab) 
{
	string STDName;
	STDName=TEATab.getTheOtherName();
	TableInfo testAddress;
	testAddress.setName(STDName);
	int cnt = 1;
	bool flag = 0;
	while (readPreFile(STDName, cnt))

	{
		string filename1, filename2;
		filename1 = this->table.getTheOtherName() + ",dat";
		filename2 = this->saveAddress.getfileName();
		if (filename1==filename2)
		{
			flag = 1;
			return cnt;
		}
		cnt++;
	}
	if (!flag) 
	{
		return -1;//没有找到则返回-1
	}
}

