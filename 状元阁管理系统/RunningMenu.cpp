#include "RunningMenu.h"
#include <iostream>
using namespace std;

RunningMenu::RunningMenu(Manager& obj):operatorManager(obj)
{
	//剩下的无需操作
}

RunningMenu::~RunningMenu() 
{
	//简简单单的析构函数

}

RunningMenu::RunningMenu(const RunningMenu& obj) 
{
	this->operatorManager = obj.operatorManager;
}

RunningMenu RunningMenu::operator= (const RunningMenu& obj)
{

	this->operatorManager = obj.operatorManager;
	return *this;
}


//唯一外部接口的display函数
void RunningMenu::display() 
// float pay, string Remarks string payer = "管理员本人", string collect = "微信支付");
{
	system("CLS");

	string PayMan, Remarks,collect;
	float payment;
	
	cout << "************************************************************" << endl << endl;
	cout << "\t\t店内流水账记录" << endl << endl;
	cout << "请输入款项事由(如有备注，一并书写):   ";
	cin >> Remarks;
	cout << "请输入金额:       ";
	cin >> payment;
	bool temp = display2();
	
	try 
	{
		if (temp)
		{
			cout << "请输入当前操作者 :   ";
			cin >> PayMan;
			cout << "请输入付款方式   :   ";
			cin >> collect;
			RunningRecord RR(this->operatorManager, payment, Remarks, PayMan, collect);
			if (!saveRunRecord(RR))
			{
				throw 936;
			}
		}
		else
		{
			RunningRecord RPP(this->operatorManager, payment, Remarks);
			if (!saveRunRecord(RPP)) 
			{
				throw 936;
			}
		}
		cout << endl;
		cout << "Success  流水记录保存成功 ！";
		cout << "此次交易具体信息如下 :   " << endl;
		cout << "管理员   "<<this->operatorManager.getName()<<endl;
		if (temp) 
		{
			cout << "经手人   " << PayMan << endl;
		}
		else 
		{
			cout << "经手人   " << this->operatorManager.getName() << endl;
		}
		cout << "金额     " << payment<<endl;
		cout << "交易备注 " << Remarks<<endl;
		if (temp)
		{
			cout << "收款方式 " << collect << endl;
		}
		else
		{
			cout << "收款方式 " << "微信支付" << endl;
		}

	}catch (int goal) 
	{
		cout << "Warning   流水账记录保存失败";
		cout << "错误代码:  " << goal << endl;
	}
	
}

bool RunningMenu::display2() 
{
	cout << "当前的流水记录者是:  ";
	cout << this->operatorManager.getName()<<endl;
	cout << "是否进行修改？如需更改默认收款方式也请选择继续...";
	cout << endl;
	if (checkToContinue())
	{
		return true;
	}
	return false;
}

bool RunningMenu::saveRunRecord(RunningRecord ThRR) 

{
	RecordInfo ADD("RunningRecord");
	ofstream file;

	file.open(ADD.getCompleteAddress(), ios::out | ios::binary | ios::app);

	if (!file)
	{
		cout << "Warning 流水记录文件打开失败  " << endl;
		cout << "请检查是否存在路径" << ADD.getCompleteAddress() << endl;
		return false;
	}
	file.write((char*)&ThRR, sizeof(ThRR));

	file.close();
	return true;

}


