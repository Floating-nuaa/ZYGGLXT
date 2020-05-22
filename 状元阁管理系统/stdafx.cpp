#pragma warning (disable:4996)
#include <time.h>
#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


bool checkBigPassword(string s) 

//第一行是BigBoss授权码
//#号结尾，后有endl
{
	
	ifstream password;
	
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;
	
	password.open(file, ios::in);
	
	if (!password) 
	{
		cout << "password.txt can't be opened!" << endl;
		throw 2514;
	}
	
	char  pass[20];
	string a;
	
	password.getline(pass, 20,'#');
	
	password.close();
	
	a = pass;
	
	if (s == a) {
		return 1;
	}
	return 0;

}

bool saveAccount(string name, string password) 

//保存账户说明：前方结尾是回车
//密码在前，账户名在后，中间 “#” 隔开
//最后有换行符

{
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;
	
	char na[20], pa[30];
	
	strcpy_s(na, name.c_str());
	strcpy_s(pa, password.c_str());
	
	ofstream f(file, ios::out|ios::app);
	
	if(!f)
	{
		cout << file << " can't be opened !" << endl;
		system("pause");
		return 0;
	}
	
	f << pa;
	
	f.put('#');
	f << na;

	f.put(10);
	
	f.close();
	
	return 1;
}

bool checkPassword(string input) 

//从密码文件中提取数据，与输入数据进行核验

{
	string  fileAddress = "E:\\VisualStudio\\Data\\";
	string fileName = "password.txt";
	string file = fileAddress + fileName;
	
	ifstream password;
	password.open(file, ios::in);
	if (!password)
	{
		cout << "password.txt can't be opened!" << endl;
		throw 2514;
	}
	char pa[30];
	string str;

	//判断读取密码,保证所有路径都有返回值，
	//用异常处理增强健壮性
	
		bool temp = 0;
		while (!password.eof()) 
		{
			password.getline(pa, 49, '#');
			str = pa;
			
			if (input == str) 
			{
				temp = 1;
				password.close();
				return 1;
			}

			char cc = password.get();
			while (!password.eof()&&cc != 10) 
			{
				cc = password.get();
			}

		}
		//如果没有查找到，抛出0
		if (!temp) {
			password.close();
			throw 0;
			return 0;
		}
		return 0;
}

bool checkSaveAddress(string saveAddress) 

//功能函数说明：
//这是检测更改文件储存路径是否合法的函数
//合法返回1 否则返回零
//会创建一个可以删除的测试文件
{

	if (saveAddress[0] != 'E' && saveAddress[0] != 'C' && saveAddress[0] != 'D') 
	{
		return 0;
	}
	if (saveAddress[1] != ':') 
	{
		return 0;
	}
	if (saveAddress[2] != '\\')
	{
		return 0;
	}
	//以上的检测很不完善，但几乎能避免因为格式不正确，引起的在相对路径下建立
	//同名文件的问题
	ofstream checkin;
	
	string  fileAddress = saveAddress;
	
	string fileName = "检测路径.txt";
	
	string file = fileAddress + fileName;
	
	checkin.open(file, ios::out);

	if (!checkin) 
	
	{
		return 0; 
	}
	checkin << "路径检测成功！！！！" << endl;
	checkin << "(本文件可以移除)" << endl;
	return 1;

	checkin.close();

}

string getStringWithoutShow()

{
	int i = 0;
	char ch,password[30];
	while ((ch = _getch()) != '\r')
	{
		if (ch == '\b' && i > 0)
		{
			printf("\b \b");
			i--;
		}
		else
		{
			password[i++] = ch;
			cout << '*';
		}
	}
	password[i] = '\0';

	string pass(password);
	cout << endl;
	return pass;
}

string TimeStampToStandard(int a ) 

{
	//time_t now;
	//int unixTime = (int)time(&now);
	int unixTime = a;
	time_t tick = (time_t)unixTime;

	struct tm tm;
	char s[100];
	tm = *localtime(&tick);

	strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
	
	string Standard(s);

	return Standard;

}

bool checkToContinue( )
{
	string temp="N";
	cout << "是否执行或继续此项操作 (Y or N)" << endl;
	cin >> temp;
	if (temp[0] != 'Y' && temp[0] != 'y') 
	{
		return false;
	}
	return true;
}

void operationCancled() 

{
	cout << "根据您输入的命令，系统做出如下反馈:   操作被取消 ！ " << endl;
}


string translateNumToClassType(int key) 
{
	map<int, string > classType;
	classType.insert(pair<int, string>(1, "一对一课程"));
	classType.insert(pair<int, string>(2, "一对二课程"));
	classType.insert(pair<int, string>(3, "一对三课程"));
	classType.insert(pair<int, string>(4, "一对四课程"));
	classType.insert(pair<int, string>(5, "小班课课程"));
	classType.insert(pair<int, string>(6, "其他类课程"));
	
	string Type = "未查找到此种课程类型 ";
	
	auto it = classType.find(key);

	if (it != classType.end())
	{
		Type = (*it).second;
	}
	return Type;

}

char checkGender() 
{
	string temp;
	cin >> temp;
	if (temp[0] == 'F' || temp[0] == 'f'||temp=="女")
	{
		return 'F';
	}
	if (temp[0] == 'M' || temp[0] == 'm'||temp=="男") 
	{
		return 'M';
	}

}

string trnaslateVioCode(int first, int second)

{
	switch (first) 
	{
		case 1:
		{
			map<int, string > VioType;
			
			VioType.insert(pair<int, string>(1, "未使用本机构统一的页眉文档格式来打印文件"));
			VioType.insert(pair<int, string>(2, "无课期间在自习室或其他教学地点玩手机"));
			VioType.insert(pair<int, string>(3, "上课时间手机没有放到指定地点"));
			VioType.insert(pair<int, string>(4, "上课期间教师之间闲聊或与学生闲聊"));
			VioType.insert(pair<int, string>(5, "未及时与家长反馈"));
			VioType.insert(pair<int, string>(6, "上课迟到但未超过5分钟"));
			VioType.insert(pair<int, string>(7, "早退"));
			VioType.insert(pair<int, string>(8, "组内没有及时进行教研"));
		
			string Type = "文件中未查找到此种类型的教学事故";
			string FT = "一级教学事故 : ";
			string Ans;
			
			auto it = VioType.find(second);

			if (it != VioType.end())
			{
				Type = (*it).second;
			}
			Ans = FT + Type;
			
			return Ans;
			
			break;
		
		}
		case 2: 
		{
			map<int, string > VioType;
			
			VioType.insert(pair<int, string>(1, "上课时间使用手机"));
			VioType.insert(pair<int, string>(2, "上课花费大量时间让学生做题"));
			VioType.insert(pair<int, string>(3, "上课迟到5分钟以上"));
			VioType.insert(pair<int, string>(4, "私自调整课表未经管理人员同意"));
			VioType.insert(pair<int, string>(5, "在有学生学习的地方，包括一楼大厅大声喧哗"));
			
			string Type = "文件中未查找到此种类型的教学事故";
			string FT = "二级教学事故 : ";
			string Ans;
			
			auto it = VioType.find(second);

			if (it != VioType.end())
			{
				Type = (*it).second;
			}
			Ans = FT + Type;
			
			return Ans;
			
			break;

		}
		case 3: 
		{
			map<int, string > VioType;
		
			VioType.insert(pair<int, string>(1, "私自向学生收费，私自接课"));
			VioType.insert(pair<int, string>(2, "不尊重管理人员，顶撞甚至辱骂"));
			VioType.insert(pair<int, string>(3, "学生未毕业前与其谈恋爱甚至被其家了解造成不良影响"));

			string Type = "文件中未查找到此种类型的教学事故";
			string FT = "二级教学事故 : ";
			string Ans;
			
			auto it = VioType.find(second);

			if (it != VioType.end())
			{
				Type = (*it).second;
			}
			
			Ans = FT + Type;
			
			return Ans;
			
			break;

		}
		default:
		{
			string Type;
			Type = "未查找到此代码代表的教学事故，请仔细阅读此次教学事故的备注!";
			return Type;
		}

	}
	
}







