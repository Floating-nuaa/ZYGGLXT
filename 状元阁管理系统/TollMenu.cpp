#include "TollMenu.h"
#include <iostream>
using namespace std;

TollMenu::TollMenu(Manager& obj ):operatorManager(obj)
{ 
	//构造函数
}

TollMenu::~TollMenu( )
{
	//析构
}


void TollMenu::display() 
	//收银菜单
{
	try 
	{
		system("CLS");
		string STDname, PayWay, Remarks;
		Student thisStud;
		cout << "************************************************************" << endl << endl << endl;
		cout << "\t\t缴纳课程费用" << endl << endl;
		cout << "请输入学生姓名 :  ";
		cin >> STDname;
		cout << endl;

		thisStud = checkSTDInfo(STDname);//

		cout << "交易提醒:  \t请核对缴费学生的个人信息...  " << endl;
		if (!checkToContinue())
		{
			operationCancled();
			return;
		}
		float payment;
		cout << "请输入所缴纳费用：  ";
		cin >> payment;
		if (display2())

		{
			cout << "请输入收款方式 :  ";
			cin >> PayWay;
			cout << "请添加备注 :  ";
			cin >> Remarks;
		}


		TransactionRecord thisTR(this->operatorManager, thisStud, payment, PayWay, Remarks);

		if (!saveThisTranRecord(thisTR))
			//如果文件保存失败	
		{
			cout << " 交易文件保存失败，请先在工作日志上记录此次收款信息，";
			cout << "并及时联系开发人员Floating " << endl;
			return;
		}

		cout << "  收银成功！ 交易详细信息如下 : " << endl;
		cout << "收银管理员姓名  " << this->operatorManager.getName() << endl;
		cout << "学生姓名        " << thisStud.getName() << endl;
		cout << "收款金额        " << payment << endl;
		system("pause");
		return;


	}catch(int goal)
	{
		cout << "Warning  学生信息获取失败，请检查是否存在" << endl;
		cout << "请检查学生姓名拼写是否正确或储存路径是否存在" << endl;
		cout << "错误代码  " << goal << endl;
	}
	
}

bool TollMenu::display2()  
{
	cout << "Tips  是否改变默认的收款方式(现金收款)或添加收款备注 " << endl;
	if (checkToContinue()) 
	{
		return true;
	}
	return false;
}

Student TollMenu::checkSTDInfo(string STDname) 
{

	OperateSTD OS;
	Student stud;
	
	if (!OS.readPreFile(STDname))
	{
		throw 4511;
	}
	
	stud = OS.getStudent();
	stud.display( );
	return stud;

}

bool TollMenu::saveThisTranRecord(TransactionRecord thisTR ) 

{
	RecordInfo ADD("TransactionRecord");
	ofstream file;
	
	file.open(ADD.getCompleteAddress(), ios::out | ios::binary | ios::app);
	
	if (!file) 
	{
		cout << "Warning 交易文件打开失败  " << endl;
		cout << "请检查是否存在路径" << ADD.getCompleteAddress() << endl;
		return false;
	}
	
	file.write((char*)&thisTR, sizeof(thisTR));
	
	file.close();


	RecordInfo SUM;
	ofstream file2;

	file2.open(SUM.getCompleteAddress(), ios::out | ios::binary | ios::app);
	
	if (!file2)
	{
		cout << "Warning 交易文件打开失败  " << endl;
		cout << "请检查是否存在路径" << SUM.getCompleteAddress() << endl;
		return false;
	}

	file2.write((char*)&thisTR, sizeof(thisTR));
	
	file2.close();
	
	return true;

}

TollMenu::TollMenu(const TollMenu& obj)
{
	this->operatorManager = obj.operatorManager;
	//拷贝构造函数
}



