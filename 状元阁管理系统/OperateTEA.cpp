#include "OperateTEA.h"
#include "PeoNum.h"
#include "PerInfo.h"

OperateTEA::OperateTEA(){}

OperateTEA::~OperateTEA(){}

OperateTEA::OperateTEA(const OperateTEA& obj) 
{
	this->teacher = obj.teacher;
}



void OperateTEA::getInfoFromScreen()

//把保护变量里的TEA 填入信息
{

	AddTEAMenu  ATM;

	ATM.display();
	teacher = ATM.getTeacher();
	string name(teacher.getName());

	TEAInfo TI(name);
	
	saveAddress = TI;
}



bool OperateTEA::saveThisFile()

//保存文件
{
	setTeasID(this->teacher);

	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);

	if (!file)

	{
		cout << "教师信息文件打开失败，请检查路径是否正确！" << endl;
		return 0;
	}

	file.write((char*)&teacher, sizeof(teacher));
	file.close();

	PerInfo PI("TotalTeacher");//创建人信息保存地址

	ofstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::app|ios::out);

	if (!perFile)
	{
		cout << "教师信息总文件打开失败，请检查路径是否正确！" << endl;

		return 0;

	}
	perFile.write((char*)&teacher, sizeof(teacher));

	perFile.close();
	
	cout << "Success  教师信息保存成功!" << endl;
	return true;
}



bool OperateTEA::readPreFile()

//从文件中读取文件信息

{
	string thisName = "test";
	cout << "请输入要查询教师的姓名:  ";
	cin >> thisName;
	cout << endl;

	saveAddress.setName(thisName);
	
	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "教师信息文件打开失败，请检查路径和姓名是否正确！" << endl;
		return 0;
	}

	file.read((char*)&teacher, sizeof(teacher));
	file.close();
	return 1;

}

bool OperateTEA::readPreFile(string name)

//从文件中读取文件信息

{
	string thisName = name ;
	saveAddress.setName(thisName);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "教师信息文件打开失败，请检查路径和姓名是否正确！" << endl;
		return 0;
	}

	file.read((char*)&teacher, sizeof(teacher));
	file.close();
	return 1;

}

bool OperateTEA::readPreFile(int oridinal) 
	//从教师总表中读出教师的数据
	//参数代表是第几个信息
{
	PerInfo PI("TotalTeacher");//创建人信息保存地址

	ifstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::in);

	if (!perFile)
	{
		cout << "教师信息总文件打开失败，请检查路径是否正确！" << endl;
		cout << "当前路径是 " << saveAddress.getCompleteAddress() << endl;
		return 0;

	}

	short t = (oridinal-1) * sizeof(this->teacher);
	
	perFile.seekg(t, ios::beg);
	
	if (perFile.eof()) 
	{
		return false;
	}
	
	perFile.read((char*)&teacher, sizeof(teacher));
	
	perFile.close();
	
	return true;

}

void OperateTEA::setTeasID(People& obj)

{
	//更改ID
	PeoNum PN;

	obj.ID = PN.returnNum();

}



bool OperateTEA::updateTeacherInfo(string  TEAname)
{

	try 
	{
		saveAddress.setName(TEAname);

		fstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary | ios::out);

		if (!file)
		{
			cout << "教师信息文件打开失败，请检查路径和姓名是否正确！" << endl;
			cout << "当前的路径是 " << saveAddress.getCompleteAddress() << endl;
			return 0;
		}

		file.read((char*)&teacher, sizeof(teacher));

		getChangeInfo();

		if (catchElection())		//如果更新了学生姓名，就更新一下文件名 
		{
			file.close();
			TEAInfo PreAddress = this->saveAddress;

			this->saveAddress.setName(this->teacher.getName());
			if (rename(PreAddress.getCompleteAddress().c_str(), this->saveAddress.getCompleteAddress().c_str()) < 0)
			{
				cout << "Warning 文件更名失败" << endl;
				cout << "原文件位置是  " << PreAddress.getCompleteAddress() << endl;
				cout << "新文件位置是  " << this->saveAddress.getCompleteAddress() << endl;
				cout << "请根据提示进行手动修改文件名称 ,感谢您的理解和配合！" << endl;

				file.open(PreAddress.getCompleteAddress(), ios::in | ios::binary | ios::out);

				file.seekp(0, ios::beg);  //指针调到开头

				file.write((char*)&teacher, sizeof(teacher)); // 写入修改后的信息

				file.close();

				cout << "Success  学生信息修改成功" << endl << endl;

				return 1;
			}
			file.open(saveAddress.getCompleteAddress(), ios::in | ios::binary | ios::out);
			//接下来是输出文件，只需要进行对更名后的文件进行刷新

		}

		file.seekp(0, ios::beg);  //指针调到开头

		file.write((char*)&teacher, sizeof(teacher)); // 写入修改后的信息

		file.close();

		cout << "Success  教师信息修改成功" << endl << endl;

		return 1;	
	
	}
	catch (int goal)
	{
		cout << "Warning  很遗憾，所有修改失败 ！！！" << endl;
		cout << "您修改了姓名信息，但是由姓名信息命名的文件更名失败" << endl;
		cout << "错误代码  " << goal << endl;
		cout << "当前文件路径" << this->saveAddress.getCompleteAddress() << endl;
		cout << "请检查数据文件是否被异常打开" << endl;
		cout << "问题未被解决请联系开发人员..." << endl;
		system("pause");
	}
	


}



/*************************************************************
		向屏幕展示现在的信息，并获得修改信息的代码是什么
**************************************************************/
void OperateTEA::getChangeInfo()
{
	system("cls");
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t教师个人信息修改" << endl;
	cout << "下面将展示当前信息,请您核对并记录要要修改的信息" << endl;
	system("pause");
	cout << "当前教师信息是  :   " << endl << endl;
	this->teacher.display();

}


/*************************************************************
		向屏幕展示现在的信息，
		获取选项代码，并调用修改的函数
		char* name, char sex, char* phone, char* QQ, Purpose subj, int salary=60
**************************************************************/
bool OperateTEA::catchElection()

{
	cout << "请 选 择 您 要 修 改 的 信 息 " << endl;
	cout << "1. 姓  名   2. 性  别   3. 手机号码  " << endl;
	cout << "4. QQ  号   5. 科  目   6. 默认时薪  " << endl;
	
	int election = 0;

	bool goon = true;
	bool setname = false;

	while (goon)
	{
		election = 0;

		while (election <= 0 || election > 6)
		{
			cout << "请输入您要修改信息的代码(1-6)" << endl;
			cin >> election;
		}
		if (election == 1)
		{
			setname = true;
		}

		if (!doChangeInfo(election))
		{
			cout << "当前信息修改失败,可能是因为选择的信息代码有误，请仔细检查" << endl;
		}

		cout << "是否继续修改其他信息 ？" << endl;
		if (!checkToContinue())
		{
			goon = false;
		}

	}
	return setname;
}



bool OperateTEA::doChangeInfo(int election)
{
	switch (election)
	{

	case 1:
	{
		string name;
		char TEAName[25];
		cout << "请输入修改后的姓名 :  ";
		cin >> name;
		strcpy_s(TEAName, name.c_str());
		this->teacher.setName(TEAName);
		return true;
	}

	case 2:
	{
		char gender;
		cout << "请输入修改后的性别 :  ";
		gender = checkGender();
		this->teacher.gender = gender;
		return true;
	}

	case 3:
	{
		string phone;
		char TEAPhone[25];

		cout << "请输入修改后的电话号码 :  ";
		cin >> phone;

		strcpy_s(TEAPhone, phone.c_str());
		this->teacher.setPhone(TEAPhone);

		return true;
	}

	case 4:
	{
		string QQ;
		char TEAQQ[25];
		cout << "请输入修改后的QQ号码 :  ";
		cin >> QQ;
		strcpy_s(TEAQQ, QQ.c_str());
		this->teacher.setQQ(TEAQQ);
		return true;
	}

	case 5:
	{
		this->teacher.sub = catchPurpose();			//获取报名科目
	}

	case 6:
	{
		int salary = 60;
		cout << "请输入修改后的时薪(纯数字) :  " << endl;
		cin >> salary;
		cout << endl;
		this->teacher.setSalary(salary);
		return true;
	}

	default:
	{
		cout << "修改失败" << endl;
		return false;
	}

	}

}



/*************************************************************
		获取科目的方法
**************************************************************/
Purpose OperateTEA::catchPurpose()

{
	vector<string> list;
	int a = 1;
	cout << "请输入教学科目数量 :  ";
	cin >> a;
	cout << endl;
	string ttt;
	cout << "请输入分别输入课程名称，中间用空格隔开 (如:语文 数学)" << endl;

	for (int i = 1; i <= a; i++)
	{
		cout << "请输入第 " << i << " 个科目 :  ";
		cin >> ttt;
		list.push_back(ttt);
	}
	if (a == 0)
	{
		ttt = "无科目";
		list.push_back(ttt);

	}
	Purpose pur(list);
	return pur;

}



Teacher OperateTEA::getTeacher() 

{

	return this->teacher;

}



