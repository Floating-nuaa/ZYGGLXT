#include "AddSTDMenu.h"
#include <iostream>
#include <string>
#include "Purpose.h"
using namespace std;

bool AddSTDMenu::display2()

{
	cout << "是否有缴纳定金和特殊需求？ Y or N ？" << endl;
	string tem;
	cin >> tem;

	if (tem[0] == 'Y')
	{
		return 1;
	}

	return 0;
}



void AddSTDMenu::display() 
{
	//姓名 性别 电话 QQ 科目 要求 定金
	//姓名 性别 电话 科目 要求 定金
	//姓名 电话 科目 要求 定金
	//姓名 科目 要求 定金
	//姓名 性别 科目 要求 定金
	
	system("cls");
	
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t添加学生信息" << endl << endl;
	cout << "\t请选择输入方式" << endl;
	cout << "  A.  1.姓名 2.性别（F or M）3.电话号码 4.QQ " << endl;
	cout << "  B.  1.姓名 2.性别（F or M）3.电话号码 " << endl;
	cout << "  C.  1.姓名 2.性别（F or M） " << endl;
	cout << "  D.  1.姓名 2.电话号码  " << endl;
	cout << "  E.  1.姓名  " << endl<<endl;
	cout << "************************************************************" << endl << endl << endl;
	


	cout << "请选择要输入的学生信息:  ";
	string goal;
	cin >> goal;
	
	system("CLS"); 
	cout << "\t\t请按照以下方式进行学生信息输入" << endl << endl;

	switch (goal[0])
	{
		case 'A': 
		{
			cout << "  A.  1.姓名 2.性别（F or M）3.电话号码 4.QQ " << endl;
			catchAndAnylasis(4);
			break;
		}

		case 'B':
		{
			cout << "  B.  1.姓名 2.性别（F or M）3.电话号码 " << endl;
			catchAndAnylasis(3);
			break;
		}
		
		case 'C':
		{
			cout << "  C.  1.姓名 2.性别（F or M）" << endl;
			catchAndAnylasis(2);
			break;
		}

		case 'D':
		{
			cout << "  D.  1.姓名 2.电话号码 " << endl;
			catchAndAnylasis(2);
			break;
		}

		case 'E':
		{
			cout << "  E.  1.姓名 " << endl << endl;
			catchAndAnylasis(1);
			break;
		}

		default: 
		{
			cout << "选择输入方式有误，请重新选择！" << endl;
		
			system("pause");

			system("CLS");
		
			display();

			break; 
		}

	}

	system("pause");
}

//char* name, char sex, char* phone, char* QQ,
//Purpose subj, string requirement , int downpayment

void AddSTDMenu:: catchAndAnylasis(int a) 

{
	string name, sex, phone, QQ, requirement;
	int downpayment = 0;
	char cname[30], csex='F', cphone[20], cQQ[20];
	Purpose purpose;

	switch (a)
	{
	
		case 4: 
		{
			cin >> name >> sex >> phone >> QQ;
			
			purpose = catchPurpose();
			
			if (display2()) 
			{
				cout << "\t\t其他需求：" << endl;
				cin >> requirement;
				cout << "\t\t订金（没有填0）： " << endl;
				cin >> downpayment;
			}

			strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);
			strcpy_s(cQQ, QQ.c_str());
			strcpy_s(cphone, phone.c_str());
			
			if (sex[0] == 'M')
			{
				csex = 'M';
			}

			if (sex[0] == 'F') 
			{
				csex = 'F';
			}

			Student std(cname,csex,cphone,cQQ,purpose,requirement,downpayment);
			
			student = std;
			
			break;
		}
		case 3: 
		{
			cin >> name >> sex >> phone;
			purpose = catchPurpose();

			if (display2())
			{
				cout << "\t\t其他需求：" << endl;
				cin >> requirement;
				cout << "\t\t订金（没有填0）： " << endl;
				cin >> downpayment;
			}

			strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);
			strcpy_s(cphone, phone.c_str());

			if (sex[0] == 'M')
			{
				csex = 'M';
			}

			if (sex[0] == 'F')
			{
				csex = 'F';
			}

			Student std(cname, csex, cphone,purpose, requirement, downpayment);

			student = std;

			break;
		}
		case 2: 
		{
			cin >> name >> phone;
			
			purpose = catchPurpose();

			if (display2())
			{
				cout << "\t\t其他需求：" << endl;
				cin >> requirement;
				cout << "\t\t订金（没有填0）： " << endl;
				cin >> downpayment;
			}

			strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);

			if (phone[0] == 'M' || phone[0] == 'F') 
			{
				if (phone[0] == 'M')
				{
					csex = 'M';
				}

				else if (phone[0] == 'F')
				{
					csex = 'F';
				}
				else 
				{
					csex = '?'; 
				}

				Student std1(cname, csex, purpose, requirement, downpayment);
				student = std1;
				break;
			}
			
			strcpy_s(cphone, phone.c_str());
			
			Student std2(cname, cphone, purpose, requirement, downpayment);

			student = std2;
			
			break;
		}
		case 1: 
		{
			cin >> name;
			purpose = catchPurpose();

			if (display2())
			{
				cout << "\t\t其他需求：" << endl;
				cin >> requirement;
				cout << "\t\t订金（没有填0）： " << endl;
				cin >> downpayment;
			}

			strcpy_s(cname, name.c_str());//strncpy(buf, str.c_str(), 10);

			Student std(cname,purpose, requirement, downpayment);

			student = std;

			break;
		}
		default: 
		{
			cout << "无此匹配项，请重新输入！";
			display();
			break;
		}
	
	}
	return;
}

Purpose AddSTDMenu::catchPurpose() 

{
	vector<string> list;
	int a = 1;
	cout << "请输入教学科目数量 :  ";
	cin >> a;
	cout << endl;
	string ttt;
	cout << "请输入分别输入课程名称" << endl;

	for (int i = 1; i <= a; i++)
	{
		cout << "请输入第 " << i << " 个科目 :  ";
		cin >> ttt;
		list.push_back(ttt);
		cout << endl;
	}
	if (a == 0)
	{
		ttt = "无科目";
		list.push_back(ttt);

	}
	Purpose pur(list);
	return pur;
}

Student AddSTDMenu::getStudent() 
{
	return this->student;
}

