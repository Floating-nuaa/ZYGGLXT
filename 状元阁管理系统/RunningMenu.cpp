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
}



//唯一外部接口的display函数
void RunningMenu::display() 
// float pay, string Remarks string payer = "管理员本人", string collect = "微信支付");
{
	system("CLS");
	string PayMan, Remarks;
	float payment;
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t店内流水账记录" << endl << endl;
	cout << "请输入款项事由(如有备注，一并书写):   "<<endl<<"\t";
	cin >> Remarks;
	cout << "请输入金额:       ";
	cin >> payment;
	if (display2())
	{
		cout << "请输入当前操作者" << endl;
	}


}

bool RunningMenu::display2() 
{
	cout << "当前的流水记录者是:  ";
	cout << this->operatorManager.getName()<<endl;
	cout << "是否进行修改？";
	if (checkToContinue())
	{
		return true;
	}
	return false;
}