#include "AddTABMenu.h"

AddTABMenu:: AddTABMenu():table()
{	
	//无参构造
}

AddTABMenu::~AddTABMenu()
{
	//析构函数
}

AddTABMenu::AddTABMenu(const AddTABMenu& obj)
{
	this->table = obj.table;
}


void AddTABMenu::display() 
//Date startDate, Date endDate,int num,int Type 
{
	string TeacherName, StudentName;
	int whenClass, classType;
	char TEAname[30];
	Student thisSTD;
	
	system("cls");

	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t学生确定课程信息" << endl ;
	cout << "请注意 : 确定课程信息前请先添加学生的个人信息 " << endl;
	cout << "请注意 : 如未添加，请返回上层菜单添加学生信息 " << endl;
	if (!checkToContinue())
	{
		operationCancled();
		return;
	}
	
	
	try 
	{
		cout << "请输入学生姓名 :  ";
		cin >> StudentName;
		thisSTD = checkThisStudent(StudentName) ;
	
		cout << "请输入教师姓名 :  ";
		cin >> TeacherName;
	
		strcpy_s(TEAname, TeacherName.c_str());
		classType = display2();
	
	
	
		cout << "\t请选择课表的输入方式" << endl;
		cout << "  A.  输入开始日期和结束日期" << endl;
		cout << "  B.  输入开始日期和课程节数" << endl;
		cout << "  C.  手动进行课程日期的选择" << endl;
		cout << "  请输入所选方式代号 :  ";
		string tem;
		cin >> tem;
		switch(tem[0]) 
		{
			case 'A': 
			{

				cout << "请输入课程是第几节课(1-5) :  ";
				cin >> whenClass;
				Date d1, d2;
				cout << "请输入开始日期" << endl;
				d1 = getDateFromScreen();
				cout << "请输入结束日期" << endl;
				d2 = getDateFromScreen();
				Table tab(&thisSTD, d1, d2, whenClass, TEAname, classType);
				this->table = tab;
				cout << "Success 课表记录成功!" << endl;
				return;
				break;
			}

			case 'B':
			{

				cout << "请输入课程是第几节课(1-5) :  ";
				cin >> whenClass;
				Date d1;
				int num = 0;
				cout << "请输入开始日期" << endl;
				d1 = getDateFromScreen();
				cout << "请输入课程节数 :  ";
				cin >> num;
				Table tab(&thisSTD, d1, num,whenClass, TEAname, classType);
				this->table = tab;
				cout << "Success 课表记录成功!" << endl;
			
				return;
				break;
			}

			case 'C':
			{
				Table tab(&thisSTD, TEAname, classType);
				this->table = tab;
				cout << "Success 课表记录成功!" << endl;
				return;
				break;
			}
		}

		return;
	}
	
	catch (int goal) 
	{	
		cout << "Warning  错误代码 " << goal << endl;
		cout << "1. 请检查学生信息是否已经创建并保存" << endl;
		cout << "2. 请检查学生姓名拼写是否正确" << endl;
		cout << "3. 任意按键返回上一层菜单" << endl;
	}

}


Student AddTABMenu::checkThisStudent(string name) 
{
	OperateSTD OS;

	if(!OS.readPreFile(name))
	{
		throw 2046;
	}
	Student stud(OS.getStudent());
	return stud;
}

int AddTABMenu::display2() 

{
	int num=0,i=0;
	while (i<4&&num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6) 
	{
		if (i == 4)
		{
			throw 2048;
		}
		if (i > 0) 
		{
			cout << "您上次输入的数字  " << num
				<< " 是非法数据，请重新输入！！" << endl;
		}
		cout << "课程类型如下 :  " << endl;
		cout << "1, 一对一课程 " << endl;
		cout << "2. 一对二课程 " << endl;
		cout << "3, 一对三课程 " << endl;
		cout << "4, 一对四课程 " << endl;
		cout << "5. 小班课课程 " << endl;
		cout << "6. 其他类课程 " << endl;
		cout << "请选择课程类型编号(如数字2代表一对二课程)" << endl;
		cout << "请输入所选编号 :  ";
		cin >> num;
	}
	return num;
}

Date AddTABMenu::getDateFromScreen() 

{
	
	int year = 2020, month = 1, day = 1;
	cout << "请选择是否输入年份 ? ";
	if (checkToContinue()) 
	{
		cout << "输入格式(年 月 日)(中间用空格隔开 如 2020 5 1 ) " << endl;
		cout << "请输入 :  ";
		cin >> year >> month >> day;
		Date ans(year, month, day);
		return ans;
	}

	else
	{
		cout << "输入格式(月 日)(中间用空格隔开 如 5 1 ) " << endl;
		cout << "请输入 :  ";
		cin >> month >> day;
		Date ans( month, day);
		return ans;
	}
}

Table AddTABMenu::getTable()
{
	return this->table;
}


