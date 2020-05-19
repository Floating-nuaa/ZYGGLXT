#include "MainEntrance.h"
#include <windows.h>
#include <tchar.h>
#include <assert.h>
#include <iostream>
using namespace std;
MainEntrance :: MainEntrance():Hander()
{
	commender = 0;
}

MainEntrance::~MainEntrance(){}

void MainEntrance::ShowThe_First()
{
	FeasibleCmd feasible;
	
	PremaryMenu* PM;
	PM = new PremaryMenu;
	PM->display();
	delete PM;
	PM = NULL;
}

void MainEntrance::ShowPre_Login() 
{

	LoginMenu* LM;
	LM = new LoginMenu;
	LM->display();
	delete LM;
	LM = NULL;
}

int  MainEntrance::ShowMain_Menu() 
{
	MainMenu mainMenu;
	mainMenu.display();
	
	this->commender=mainMenu.getCommend();
	return this->commender;
}

bool MainEntrance::DealFirt_Comd(int Comd ) 
{

	/*******************************************************************************

		先检测登录状态，如果没有登录，而且选择的是需要权限的功能，就提醒登录
		若已经登录，则直接选择功能


	********************************************************************************/

	if (Comd == 0)
	{
		return false;
	}

	if (Comd == 9) 
	{
		cout << "状元阁提醒您 : 您即将进入内部功能通道 " << endl << endl;
		return false;
	}

	if (!this->Hander.getStatus()&&Comd !=4&&Comd!=6&&Comd!=7&&Comd!=8)
	{
		cout << "您尚未获得此项功能的权限,请您先进行登录，再使用此项功能!" << endl;
		cout << "是否现在进行登录?";
		
		if (!checkToContinue()) 
		{
			operationCancled();
			return 0;
		}

		Comd = 8;
	}

	switch (Comd) 
	{
		case 1:
		{
			cout << "状元阁提醒您 : 您即将使用学员报名功能 " << endl<<endl;
			system("pause");
			this->Hander.addSTD();//
			cout << "报  名  完  毕" << endl;
			break;

		}
		case 2: 
		{
			cout << "状元阁提醒您 : 您即将使用学员订课功能 " << endl<<endl;
			system("pause");
			this->Hander.addTAB();
			cout << "订  课  完  毕" << endl;
			break;
		}
		case 3: 
		{
			cout << "状元阁提醒您 : 您即将使用学员订课功能 " << endl << endl;;
			system("pause");
			this->Hander.addToll();
			cout << "缴  费  完  毕" << endl;
			break;
		}
		case 4: 
		{
			int temp = 0;
			string name;
			
			OperateTable operateTable;
			operateTable.clearHidenTable();

			while (temp <= 0 || temp > 3)
			{
				cout << "1. 查询教师的课表 " << endl;
				cout << "2. 查询学生的课表 " << endl;
				cout << "请输入所选功能 :  ";
				cin >> temp;
			}

			if (temp == 1)
			{
				cout << "请输入教师姓名 :  ";
			}
			else if (temp == 2)
			{
				cout << "请输入学生姓名 :  ";
			}
			
			cin >> name;
			int cnt = 1;
			if (!operateTable.readPreFile(name, 1))
			{
				cout << "读取 " << name << " 的课表失败！" << endl;
				return 0;
			}

			do
			{
				Table table;
				table = operateTable.getTable();
				if (temp == 1)
				{
					table.displayTEA();
				}
				else if (temp == 2)
				{
					table.displaySTD();
				}
				
				cnt++;
				cout << "是否查看 " << name << " 的下一个课表";
				if (!checkToContinue())
				{
					cout << "查询课表结束!  " << endl;
					break;
				}

			} while (operateTable.readPreFile(name, cnt));

			cout << "查询课表结束!  " << endl;
			break;
		}

		case 5: 
		{
			cout << "状元阁提醒您 : 您即将使用修改课表功能 " << endl << endl;
			this->Hander.setTable();
			cout << "课 表 修  改  完  毕" << endl;
			break;
		}
		case 6: 
		{
			int temp = 0;
			string name;
			OperateTable operateTable;

			operateTable.clearHidenTable();
			temp = 0;

			while (temp <= 0 || temp > 2 )
			{
				cout << "1. 生成教师的可视化课表 " << endl;
				cout << "2. 查询学生的可视化课表 " << endl;
				cout << "请输入所选功能 :  ";
				cin >> temp;
			}
			if (temp == 1) 
			{
				cout << "请输入教师姓名 :  ";
			}
			else if (temp == 2)
			{
				cout << "请输入学生姓名 :  ";
			}
			cin >> name;

			int cnt = 1;
			
			if (!operateTable.readPreFile(name, 1))
			{
				cout << "读取 " << name << " 的课表失败！" << endl;
				return 0;
			}

			bool flag = false;

			do
			{
				if (temp == 1)
				{
					operateTable.transformTTToCSV();
					if (!flag) 
					{
						flag = true;
						cout << "生成 " << name << " 的可视化课表成功！" << endl;
						cout << "请前往路径" << operateTable.getAddress() << "下查看" << endl << endl;
					}
					
				}
				else if (temp == 2) 
				{
					operateTable.transformSTToCSV();
					if (!flag)
					{
						flag = true;
						cout << "生成 " << name << " 的可视化课表成功！" << endl;
						cout << "请前往路径" << operateTable.getAddress() << "下查看" << endl << endl;
					}
				}
				cnt++;

			} while (operateTable.readPreFile(name, cnt));

			break;
		}

		case 7: 
		{
			cout << "此部分功能将在教师制作好自己的个人介绍后启用" << endl;
			cout << "即将打开状元阁试行网站 ...";
			if (!checkToContinue())
			{
				operationCancled();
				return 0;
			}
			//打开一个试用的网站
			ShellExecute(NULL, _T("open"), _T("explorer.exe"), _T("https://github.com/Flaoting/ZYGGLXT"), NULL, SW_SHOW);
			
			break;
		}

		case 8: 
		{
			int i = 0;
			do 
			{
				i++;
				if (i > 3)
				{
					break;
				}
				cout << "您即将进行管理员登录,请注意周围环境安全!" << endl;
				if (!checkToContinue())
				{
					operationCancled();
					return 0;
				}
				string name, SSH;

				cout << "请输入管理员姓名 :  ";
				cin >> name;
				cout << "请输入管理员密码 :  ";
				SSH = getStringWithoutShow();
				if (Hander.LoginManager(name, SSH)) 
				{
					return 1; //登录成功就返回
				}
				cout << "是否继续登录?";

			} while (checkToContinue());
			break;
		}

	}
	return 1;
}


int  MainEntrance::ShowInde_Menu() 
{
	InsideMenu insideMenu;
	insideMenu.display();

	this->commender = insideMenu.getCommend();
	return this->commender;
}


bool MainEntrance::DealSecn_Comd(int Comd)
{

	if (Comd == 12) 
	{
		cout << "状元阁提醒您 : 您即将使用进入管理员功能页面 " << endl << endl;
		return false;
	}

	if (Comd == 0) 
	{
		return false;
	}

	if (!this->Hander.getStatus() &&Comd!=1&& Comd != 2 && Comd != 3 && Comd != 5 && Comd != 6&& Comd != 7&&Comd != 9&& Comd != 10)
	{
		cout << "您尚未获得此项功能的权限,请您先进行登录，再使用此项功能!" << endl;
		cout << "即将为您返回上一界面" << endl;
		return false;
	}
	
	switch (Comd) 
	{
		
		case 1:
		{
			int temp = 0;
			
			cout << "状元阁提醒您 : 您即将使用进入注册管理员页面 " << endl << endl;
			
			while (temp <= 0 || temp > 2) 
			{
				cout << "1. 注册新的管理员 " << endl;
				cout << "2. 修改当前登录管理员密钥" << endl;
				cout << "请选择您要使用的功能 :  ";
				cin >> temp;
			}

			if (temp == 1) 
			{
				RegisterManagerMenu RMM;
				RMM.display();
				cout << "创 建 管 理 员 完 毕 !!!" << endl;
			}

			else if (temp == 2)
			{
				this->Hander.changeMAGSSH();
				
			}
			break;
		}

		case 2:
		{
		
			OperateTEA operateTEA;
			Teacher test;
			
			operateTEA.readPreFile();
			test = operateTEA.getTeacher();
			
			test.display();
			cout << "教 师 " << test.getName() << " 信 息 展 示 完 毕" << endl;

			break;
		
		}

		case 3: 
		{
			OperateSTD operateSTD;
			Student std;
			operateSTD.readPreFile();
			std = operateSTD.getStudent();
			std.display();
			cout << "学 生 " << std.getName() << " 信 息 展 示 完 毕" << endl;
			break;
		}

		case 4:
		{
			OperateTEA operateTEA;
			operateTEA.getInfoFromScreen();
			operateTEA.saveThisFile();
			cout << "添 加 教 师 信 息 完 毕 " << endl;
			break;
		}

		case 5: 
		{
			cout << "状元阁提醒您 : 您即将使用修改教师信息的功能 " << endl << endl;
			OperateTEA operateTEA;
			string name;
			do 
			{
				cout << "请输入要更改教师的姓名 :  ";
				cin >> name;
				
				operateTEA.updateTeacherInfo(name);

				cout << "是否要继续修改其他教师的信息？  ";

			} while (checkToContinue());

			break;
		}

		case 6: 
		{
			cout << "状元阁提醒您 : 您即将使用修改学生信息的功能 " << endl << endl;
			OperateSTD operateSTD;
			string name;
			do
			{
				cout << "请输入要更改教师的姓名 :  ";
				cin >> name;

				operateSTD.updateStudentInfo(name);

				cout << "是否要继续修改其他学生的信息？  ";

			} while (checkToContinue());
			break;
		}

		case 7:
		{
			OperateTEA operateTEA;
			string name;
			Teacher tea;
			cout << "状元阁提醒您  您即将使用查询教师工资表的功能!!!" << endl;
			do 
			{

				cout << "请输入要查询的教师姓名 :  ";
				cin >> name;
				if (!operateTEA.readPreFile(name)) 
				{
					cout << "教师 " << name << "的个人信息查找失败" << endl;
				}
				else 
				{

					tea = operateTEA.getTeacher();
					SalaryTable salaryTable(tea);
					int temo=0;
					while (temo <= 0 || temo > 2) 
					{

						cout << "1. 展示工资表详细信息" << endl;
						cout << "2. 展示工资表简要信息" << endl;
						cout << "请选择您要使用的功能 :  ";
						cin >> temo;
					}
				
					if(temo==1)
					{
						salaryTable.showAllTable();
					}

					else if (temo == 2)
					{
					salaryTable.briefShow();
					}
					cout << "教师 "<<name<<" 的工资表展示完毕"<<endl;
				}
				cout << "是否要继续查询其他教师的工资表";
			} while (checkToContinue());
			break;
		}

		case 8: 
		{
			do 
			{
				this->Hander.addVio();
				cout << "教 学 事 故 记 录 完 毕 " << endl;
				cout << "是否继续添加教学事故？  ";
			} while (checkToContinue());
			break;
		}

		case 9: 
		{
			cout << "课程单价如下 :  " << endl;
			cout << setw(10) <<"课程类型"
				<< setw(5) << "课程单价" << setw(10) << "元/小时/人" << endl;
			ConClassPrice CCP;
			map<int, ClassPrice> Price = CCP.getMapFromCon();

			for (int i = 1; i <= 6; i++) 
			{
				auto it = Price.find(i);

				ClassPrice CP(-1, -1, -1, "test");

				if (it != Price.end())
				{
					CP = (*it).second;
					cout << setw(10) << translateNumToClassType(i)
						<<setw(5) << CP.getInPrice()<<setw(10) << "元/小时/人" << endl;
				}
			}
			break;
		}

		case 10:
		{
			do 
			{
			this->Hander.addRun();
			
			cout << "是否继续添加流水账 ?";

			} while (checkToContinue());
			break;
		}

		case 11:
		{
			cout << "状元阁提醒您 : 您即将使用查询系统记录的功能" << endl;
			cout << "状元阁提醒您 : 此项功能需要验证管理员密钥  " << endl;

			while (!this->Hander.checkSSH())
			{
				cout << "密 钥 验 证 失 败 " ;
				cout << "是 否 继 续 尝 试 ？";
				if (!checkToContinue()) 
				{
					operationCancled();
					return 0;
				}
			}
			
			int temp = 0,smaller=1;
			int start = 1, end = 20;

			while (temp <= 0 || temp > 6) 
			{
				cout << "1. 查询一个范围内的收银记录" << endl;
				cout << "2. 查询一个范围内流水账" << endl;
				cout << "3. 查询一个范围内教学事故" << endl;
				cout << "4. 查询所有收银记录" << endl;
				cout << "5. 查询所有流水账" << endl;
				cout << "6. 查询所有教学事故" << endl;
				cout << "请选择您要使用的功能 :  ";
				cin >> temp;
			}

			if(temp==1||temp==2||temp==3)
			{
				cout << "请输入记录从多少条开始 :  ";
				cin >> start;
				cout << "请输入记录到多少条结束 :  ";
				cin >> end;
			}
			
			cout << "是否改变默认的显示模式(简洁模式)";
			if (checkToContinue())
			{
				cout << "1. 简洁模式 " << endl;
				cout << "2. 详细模式 " << endl;
				cout << "请选择显示模式 :  ";
				cin >> smaller;
			}

			switch (temp)
			{
				case 1: 
				{
					try 
					{
						cout << "即将展示所有的交易记录 " << endl;
						for (int i = start; i <= end; i++)
						{
							this->Hander.showOneToll(i, smaller);
						}
					}
					catch (int) 
					{
						break;
					}
					break;
				}
				case 2: 
				{
					try 
					{
						cout << "即将展示所有的流水账记录 " << endl;
						for (int i = start; i <= end; i++)
						{
							this->Hander.showOneRun(i, smaller);
						}
					}
					catch (int) 
					{
						break;
					}
					break;
				}
				case 3: 
				{

					try 
					{
						cout << "即将展示所有的教学事故记录 " << endl;

						for (int i = start; i <= end; i++)
						{
							this->Hander.showOneVio(i);
						}
					
					}
					catch (int) 
					{
						break;
					}

					break;
				}
				case 4: 
				{
					this->Hander.showAllToll(smaller);
					cout << "所有收银记录展示完毕" << endl;
					break;
				}
				case 5: 
				{
					this->Hander.showAllRun(smaller);
					cout << "所有流水记录展示完毕" << endl;
					break;
				}
				case 6:
				{
					this->Hander.showAllVio();
					cout << "所有教学事故记录展示完毕" << endl;
					break;
				}
			}
		}
	}

}

int  MainEntrance::ShowMang_Menu() 
{
	if (!this->Hander.getStatus()) 
	{
		cout << "您尚未获得此项功能的权限,请您先进行登录，再使用此项功能!" << endl;
		cout << "即将为您返回上一界面" << endl;
		return 0;
	}

	system("cls");
	cout << "*************************************************************************" << endl << endl << endl;
	cout << "\t\t状元阁管理系统" << endl << endl << endl;
	cout << "\t1. 查询所有教师信息  2. 修改文件储存位置   3. 一键统计总收入   " << endl << endl;
	cout << "\t4. 查询所有学生信息  5. 初始化课程单价     6.修改课程单价 " << endl << endl;
	cout << endl<<endl;
	cout << "*************************************************************************" << endl << endl;
	
	int com=0;
	
	do 
	{
		cout << "请输入您要使用功能的编号 :  ";
		cin >> com;
	} while (com < 0 || com > 6);


	this->commender = com;
	
	if (com == 0)
	{
		return com;
	}
	
	switch (com) 
	{
		case 1: 
		{
			cout << "即将展示所有教师的个人信息" << endl;

			this->Hander.showAllTEA();
			cout << "展 示 完 毕 " << endl;
			break;

		}
		case 2: 
		{

			BaseFile BF;
			cout << "您即将修改文件的储存位置" << endl;
			BF.changeSaveAddress();
			cout << "修 改 完 毕" << endl;
			break;
		}

		case 3: 
		{
			int cnt = 0,tem = 0;
			while(!this->Hander.checkSSH()&&cnt<3) 
			{
				cnt++;
				cout << "身份验证失败，是否继续尝试" << endl;
				if (!checkToContinue()) 
				{
					operationCancled();
					return -1;
				}

			}

			cout << "即将进行总账单的展示.... " << endl;
			cout << "是否要简要的展示每笔交易记录?";
			if (checkToContinue()) 
			{
				tem = 1;
			}
			tem=(int)this->Hander.checkSummery(tem);

			cout << "经验证交易记录，所有收银共计 " << tem << " 元" << endl;
			system("pause");
			break;
		}
		case 4: 
		{
			cout << "即将展示所有学生的个人信息" << endl;

			this->Hander.shouwAllSTD();
			break;
		}
		case 5: 
		{
			cout << "状元阁提示您，您即将初始化课程单价，请注意，所有单位都是 元/小时/人" << endl;
			
			ConClassPrice CCP;
			CCP.initClassPrice();
			cout << "初 始 化 完 毕 " << endl;
			break;
		}


		case 6: 
		{
			cout << "状元阁提示您，您即将修改课程单价，请注意，所有单位都是 元/小时/人" << endl;

			ConClassPrice CCP;
			CCP.initClassPrice();
			cout << " 修 改 完 毕 " << endl;
			break;
		}

	}
	return 1;

}





