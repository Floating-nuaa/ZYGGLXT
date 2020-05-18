#include "SalaryTable.h"




SalaryTable::SalaryTable(Teacher& obj):teacher(obj)
{
	this->totalSalary = 0;
	caculateSalary();//计算一下总工资
}

SalaryTable::SalaryTable(const SalaryTable& obj) 
{
	this->teacher = obj.teacher;
	this->totalSalary = obj.totalSalary;
}

SalaryTable::~SalaryTable() 
{
	//析构函数，无需操作
}

SalaryTable SalaryTable::operator =(const SalaryTable& obj) 
{

	this->teacher = obj.teacher;
	this->totalSalary = obj.totalSalary;
	return *this;
}

/*初始化时用来计算总工资*/
void SalaryTable::caculateSalary() 
{
	string name = this->teacher.getName();
	OperateTable OT;
	Table T;
	int i = 1;
	int summery = 0;

	if (!OT.readPreFile(name, i))
	{
		cout << "计算总工资时文件读取失败" << endl;
		return ;
	}

	do
	{
		T = OT.getTable();
		int price = getClassTypeOutPrice(T.getClassType());
		int sum = T.getNum() * 2 * price;
		summery += sum;
		i++;
		OT.clearHidenTable();
	} while (OT.readPreFile(name, i));

	this->totalSalary=summery;

}

void SalaryTable::showAllTable()
{
//展示这位老师的所有课表
	cout << "教师 " << this->teacher.getName() << " 的总工资为"
		<< setw(8) << this->totalSalary << "   元 " << endl;
	cout << "下面将展示此此位老师的所有课程工资小结...." << endl;
	cout << endl;
	int total = 0;
	total= HowMuchInDisplay();
	cout << "经过严格计算, ";
	cout << "教师 " << this->teacher.getName() << " 的总工资为"
		<< setw(8) << this->totalSalary << "   元 " << endl;

}

void SalaryTable::briefShow() 
{
//进行简短的展示
	int summery = 0;
	
	cout << "教师 " << this->teacher.getName() << " 的总工资为"
		<< setw(8) << this->totalSalary << "   元 " << endl;
	summery = HowMuchInShort();
	
	cout << "经过严格计算, ";
	cout << "教师 " << this->teacher.getName() << " 的总工资为"
		<< setw(8) << this->totalSalary << "   元 " << endl;

}

int SalaryTable::getClassTypeOutPrice(int key)
{
	ConClassPrice CCP;
	map<int, ClassPrice> Price = CCP.getMapFromCon();

	auto it = Price.find(key);

	ClassPrice CP(-1, -1, -1, "test");

	if (it != Price.end())
	{
		CP = (*it).second;
		return CP.getOutPrice();
	}
	return -1;
}


int SalaryTable::HowMuchInDisplay()
{
	string name = this->teacher.getName();
	OperateTable OT;
	Table T;
	int i = 1;
	int summery = 0;

	if (!OT.readPreFile(name, i))
	{
		cout << "计算总工资时文件读取失败" << endl;
		return 0;
	}

	do
	{
		T = OT.getTable();
		T.shortShowTEA();		//这里好像有bug
		cout << endl;
		int price = getClassTypeOutPrice(T.getClassType());
		int sum = T.getNum() * 2 * price;
		
		cout << "课程单价 " << setw(5) << price << setw(5) << "元/人/小时" << endl;
		cout << "此节课小计 " << setw(5) << sum << setw(5) << " 元 " << endl;
		
		summery += sum;
		i++;
		
		OT.clearHidenTable();
		system("pause");
	} while (OT.readPreFile(name, i));

	return summery;

}

int SalaryTable::HowMuchInShort()
{
	string name = this->teacher.getName();
	OperateTable OT;
	Table T;
	int i = 1;
	int summery = 0;

	if (!OT.readPreFile(name, i))
	{
		cout << "计算总工资时文件读取失败" << endl;
		return 0;
	}

	do
	{
		
		T = OT.getTable();
		T.shortShortShowTEA();	//这里好像有bug
		cout << endl;
		int price = getClassTypeOutPrice(T.getClassType());
		int sum = T.getNum() * 2 * price;
	
		cout << "此节课小计 " << setw(5) << sum << setw(5) << " 元 " << endl;
		summery += sum;
		
		i++;
		
		OT.clearHidenTable();
		system("pause");
	
	} while (OT.readPreFile(name, i));

	return summery;
}


