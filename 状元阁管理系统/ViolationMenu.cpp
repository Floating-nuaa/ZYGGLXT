#include "ViolationMenu.h"
#include <iostream>

using namespace std;



ViolationMenu::ViolationMenu(Manager &obj):operatorManager(obj)
{
	//其他的无需操作
}

ViolationMenu::ViolationMenu(const ViolationMenu& obj)
{
	this->operatorManager = obj.operatorManager;
}



ViolationMenu:: ~ViolationMenu() 
{
	//析构函数，无需操作
}



void ViolationMenu::display()
{
	try
	{
		system("CLS");
		
		cout << "************************************************************" << endl << endl;
		cout << "友情提示  教学事故记录前请先检查教师个人信息已经录入系统" << endl;
		cout << "友情提示  教学事故记录一经记录无法修改或删除，请谨慎操作" << endl;
		
		if (!checkToContinue())
		{
			operationCancled();
			return;
		}
		
		system("cls");
		
		string TeaName, remarks;
		Teacher tea;
		int first, second;
		Date occurTime;
		
		cout << "************************************************************" << endl << endl;
		cout << "\t\t教学事故记录" << endl << endl;
		cout << "接下来将展示教学事故具体细节，请核对并记录此次违规属于的级别" << endl;
		system("pause");
		system("cls");

		display2();
		
		first = getFirst();
		second = getSecond(first);
		cout << "请输入教师姓名 :  ";
		cin >> TeaName;
		tea = checkThisTEA(TeaName);
		cout << "请输入记录备注 :  ";
		cin >> remarks;
		cout << "下面请您输入事件发生时间" << endl;
		occurTime = getOTD();

		cout << "友情提示  教学事故记录已经记录无法修改或删除，请谨慎操作" << endl;
		if (!checkToContinue())
		{
			operationCancled();
			return;
		}

		ViolationRecord VM(operatorManager, tea, first, second, occurTime, remarks);
		if (saveThisRecord(VM))
		{
			cout << "此次记录保存成功!!"<<endl;
		}
		else
		{
			cout << "此次记录保存失败" << endl;
		}
		return;
	}
	catch(int)
	{
		cout << "教师信息打开失败,请检查教师信息是否存在或姓名的拼写是否正确" << endl;
		cout << "如不存在，请先创建教师信息!!!" << endl;
	}
	
}



void ViolationMenu ::display2() 
{
	cout << "\t一级教学事故" << endl;
	cout << "\t\t1.未使用本机构统一的页眉文档格式来打印文件" << endl;
	cout << "\t\t2.无课期间在自习室或其他教学地点玩手机" << endl;
	cout << "\t\t3.上课时间手机没有放到指定地点" << endl;
	cout << "\t\t4.上课期间教师之间闲聊或与学生闲聊" << endl;
	cout << "\t\t5.未及时与家长反馈" << endl;
	cout << "\t\t6.上课迟到但未超过5分钟" << endl;
	cout << "\t\t7.早退" << endl;
	cout << "\t\t8.组内没有及时进行教研" << endl;
	
	cout << "\t二级教学事故" << endl;
	cout << "\t\t1.上课时间使用手机" << endl;
	cout << "\t\t2.上课花费大量时间让学生做题" << endl;
	cout << "\t\t3.上课迟到5分钟以上" << endl;
	cout << "\t\t4.私自调整课表未经管理人员同意" << endl;
	cout << "\t\t5.在有学生学习的地方，包括一楼大厅大声喧哗" << endl;
		
	cout << "\t三级教学事故" << endl;
	cout << "\t\t1.私自向学生收费，私自接课" << endl;
	cout << "\t\t2.不尊重管理人员，顶撞甚至辱骂" << endl;
	cout << "\t\t3.学生未毕业前与其谈恋爱甚至被其家了解造成不良影响" << endl;

	return;
}



int ViolationMenu::getFirst()
{
	system("pause");
	system("cls");
	int f=0;

	while (f <= 0 || f > 4)
	{
		if (f != 0)
		{
			
			cout << "输入代号有误，请再次输入！！" << endl;
		}
		cout << "1. 一级教学事故" << endl;
		cout << "2. 二级教学事故" << endl;
		cout << "3. 三级教学事故" << endl;
		cout << "4. 其他教学事故" << endl;
		cout << "请输入教学事故等级(1-4) :   ";
		cin >> f;
	}
	return f;
}



int ViolationMenu::getSecond(int first)

{
	system("cls");
	switch (first) 
	{
		case 1: 
		{
			cout << "一级教学事故" << endl;
			cout << "\t1.未使用本机构统一的页眉文档格式来打印文件" << endl;
			cout << "\t2.无课期间在自习室或其他教学地点玩手机" << endl;
			cout << "\t3.上课时间手机没有放到指定地点" << endl;
			cout << "\t4.上课期间教师之间闲聊或与学生闲聊" << endl;
			cout << "\t5.未及时与家长反馈" << endl;
			cout << "\t6.上课迟到但未超过5分钟" << endl;
			cout << "\t7.早退" << endl;
			cout << "\t8.组内没有及时进行教研" << endl;
			break;
		}
		case 2:
		{
			cout << "二级教学事故" << endl;
			cout << "\t1.上课时间使用手机" << endl;
			cout << "\t2.上课花费大量时间让学生做题" << endl;
			cout << "\tt3.上课迟到5分钟以上" << endl;
			cout << "\t4.私自调整课表未经管理人员同意" << endl;
			cout << "\t5.在有学生学习的地方，包括一楼大厅大声喧哗" << endl;
			break;
		}
		case 3:
		{
			cout << "三级教学事故" << endl;
			cout << "\t1.私自向学生收费，私自接课" << endl;
			cout << "\t2.不尊重管理人员，顶撞甚至辱骂" << endl;
			cout << "\t3.学生未毕业前与其谈恋爱甚至被其家了解造成不良影响" << endl;
			break;
		}

		case 4:
		{
			cout << "其他类型教学事故" << endl;
			cout << "1. 请输入代码1，并仔细添加备注" << endl;
			break;
		}
	}
	cout << endl;
	cout << "请输入此次事件代码 :  ";

	int t;
	cin >> t;
	return t;
}



Teacher ViolationMenu::checkThisTEA(string name) 

{
	OperateTEA OT;
	Teacher tea;
	if (!OT.readPreFile(name))
	{
		throw 4511;
	}
	tea = OT.getTeacher();
	return tea;
}



Date ViolationMenu::getOTD() 
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
		Date ans(month, day);
		return ans;
	}
}



bool ViolationMenu::saveThisRecord(ViolationRecord& VR) 


{
	RecordInfo ADD("ViolationRecord");
	ofstream file;

	file.open(ADD.getCompleteAddress(), ios::out | ios::binary | ios::app);

	if (!file)
	{
		cout << "Warning 记录文件打开失败  " << endl;
		cout << "请检查是否存在路径" << ADD.getCompleteAddress() << endl;
		return false;
	} 

	file.write((char*)&VR, sizeof(VR));

	file.close();

	return true;

}


