#include "OperateSTD.h"
#include "PeoNum.h"
#include "AddSTDMenu.h"
#include "PerInfo.h"
#include <io.h>
#include <fcntl.h>
#include <fstream>


OperateSTD::OperateSTD() {}



OperateSTD::~OperateSTD(){}



void OperateSTD::getInfoFromScreen()

//把保护变量里的STD 填入信息

{
	AddSTDMenu  ASM;

	ASM.display();
	stud =  ASM.getStudent();
	string name(stud.getName());

	STDInfo SI(name);
	saveAddress = SI;
}



bool OperateSTD::saveThisFile() 
{
	setStdsID(this->stud);

	ofstream file(saveAddress.getCompleteAddress(), ios::out | ios::binary);

	if (!file) 
	
	{
		cout << "学生个人信息文件打开失败，请检查路径是否正确！" << endl;
		return 0;
	}
	
	file.write((char*)&stud, sizeof(stud));
	file.close();

	PerInfo PI("TotalStudent");//创建人信息保存地址
	
	ofstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary |ios::app|ios::out);
	
	if (!perFile) 
	{
		cout << "学生信息总文件打开失败，请检查路径是否正确！" << endl;

		cout << "当前路径是 :  " << PI.getCompleteAddress() << endl;
		
		return 0;

	}
	perFile.write((char*)&stud, sizeof(stud));
	perFile.close();
	cout << "学生" << this->stud.getName() << " 的信息保存成功" << endl;
	cout << "保存路径为 :  " << saveAddress.getCompleteAddress() << endl;
	return 1;
}



bool OperateSTD::readPreFile( ) 
	
	//读出信息，储存在私有域中

{
	string thisName="test";
	cout << "\t请输入要查询学生的姓名:  ";
	cin >> thisName;
	cout << endl;
	saveAddress.setName(thisName);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)

	{
		cout << "学生信息文件打开失败，请检查路径和姓名是否正确！" << endl;
		return 0;
	}

	file.read((char*)&stud, sizeof(stud));
	file.close();
	//student.display();
	return 1;

}

bool OperateSTD::readPreFile(string STDname)
{
	saveAddress.setName(STDname);

	ifstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "学生信息文件打开失败，请检查路径和姓名是否正确！" << endl;
		cout << "当前的路径是 " << saveAddress.getCompleteAddress() << endl;
		return 0;
	}
	file.read((char*)&stud, sizeof(stud));
	
	file.close();
	return 1;
}

bool OperateSTD::readPreFile(int oridinal)
//从学生总表中读出教师的数据
//参数代表是第几个信息
{
	PerInfo PI("TotalStudent");//创建人信息保存地址

	ifstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::in);

	if (!perFile)
	{
		cout << "学生信息总文件打开失败，请检查路径是否正确！" << endl;
		cout << "当前路径是 " << saveAddress.getCompleteAddress() << endl;
		return 0;

	}

	short t = (oridinal - 1) * sizeof(this->stud);

	perFile.seekg(t, ios::beg);

	if (perFile.eof())
	{
		return false;
	}

	perFile.read((char*)&this->stud, sizeof(this->stud));

	perFile.close();

	return true;

}

Student OperateSTD::getStudent() 

{
	return this->stud;
}



void OperateSTD::setStdsID(People& obj) 

{
	//更改ID
	PeoNum PN;

	obj.ID = PN.returnNum();

}



bool OperateSTD::updateStudentInfo(string  STDname) 
{

	saveAddress.setName(STDname);

	fstream file(saveAddress.getCompleteAddress(), ios::in | ios::binary|ios::out);

	if (!file)
	{
		cout << "学生信息文件打开失败，请检查路径和姓名是否正确！" << endl;
		cout << "当前的路径是 " << saveAddress.getCompleteAddress() << endl;
		return 0;
	}

	file.read((char*)&stud, sizeof(stud));
	
	getChangeInfo();

	if (catchElection())		//如果更新了学生姓名，就更新一下文件名 
	{   
		file.close();
		STDInfo PreAddress = this->saveAddress;

		this->saveAddress.setName(this->stud.getName());
		if(rename(PreAddress.getCompleteAddress().c_str(), this->saveAddress.getCompleteAddress().c_str())<0)
			cout <<"更名失败";
		file.open(saveAddress.getCompleteAddress(), ios::in | ios::binary | ios::out);
	}
	
		file.seekp(0, ios::beg);  //指针调到开头

		file.write((char*)&stud, sizeof(stud)); // 写入修改后的信息

		file.close();

		cout << "Success  学生信息修改成功" << endl<<endl;

		return 1;
	


}



/*************************************************************
		向屏幕展示现在的信息，并获得修改信息的代码是什么
**************************************************************/
void OperateSTD:: getChangeInfo()   
{
	system("cls");
	cout << "************************************************************" << endl << endl << endl;
	cout << "\t\t学生个人信息修改" << endl;
	cout << "下面将展示当前信息,请您核对并记录要要修改的信息" << endl;
	system("pause");
	cout << "当前学生信息是  :   " << endl<<endl;
	this->stud.display();
	
}


/*************************************************************
		向屏幕展示现在的信息，
		获取选项代码，并调用修改的函数
**************************************************************/
bool OperateSTD::catchElection()

{
	cout << "请 选 择 您 要 修 改 的 信 息 " << endl;
	cout << "1. 姓  名   2. 性  别   3. 手机号码  " << endl;
	cout << "4. 定  金   5. 科  目   6. 特殊需求  " << endl;
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

		doChangeInfo(election);
		cout << "是否继续修改其他信息 ？" << endl;
		if (!checkToContinue()) 
		{
			goon = false;
		}

	}
	return setname;
}



bool OperateSTD::doChangeInfo(int election)
{
	switch (election)
	{
		
		case 1: 
		{
			string name;
			char STDName[25];
			cout << "请输入修改后的姓名 :  ";
			cin >> name;
			strcpy_s(STDName, name.c_str());
			this->stud.setName(STDName);
			return true;
		}
		
		case 2:
		{
			char gender;
			cout << "请输入修改后的性别 :  ";
			gender = checkGender();
			this->stud.gender = gender;
			return true;
		}
		
		case 3: 
		{
			string phone;
			char STDPhone[25];
			
			cout << "请输入修改后的电话号码 :  ";
			cin >> phone;
			
			strcpy_s(STDPhone, phone.c_str());
			this->stud.setPhone(STDPhone);

			return true;
		}
		
		case 4:
		{
			int pay;
			cout << "请输入修改后的定金 :  ";
			cin >> pay;
			this->stud.downPayment = pay;
			return true;
		}
		
		case 5:
		{
			this->stud.sub = catchPurpose();			//获取报名科目
		}
		
		case 6:
		{
			string requirement;
			cout << "请输入修改后的特殊需求" << endl;
			cout << "请输入 :  ";
			cin >> requirement;
			strcpy_s(this->stud.requirement, requirement.c_str());
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
Purpose OperateSTD::catchPurpose()

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

