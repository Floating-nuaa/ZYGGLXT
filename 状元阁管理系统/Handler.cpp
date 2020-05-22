#include "Handler.h"

Handler::Handler():operatorManager()
{
	//构造函数，无需操作
	this->LOGIN = false;
}

Handler:: ~Handler()
{
	//析构函数
}


bool Handler::LoginManager(string name, string SS) 
{
	string addName = "MagInfo//" + name;

	PerInfo PIP(addName);
	ifstream PrtFile;

	PrtFile.open(PIP.getCompleteAddress(), ios::out | ios::binary);

	if (!PrtFile)
	{
		cout << " Manager 读取表创建失败！" << endl;
		cout << "请检测路径" << PIP.getCompleteAddress() << "是否存在！";
		return 0;
	}

	PrtFile.read((char*)&this->operatorManager, sizeof(this->operatorManager));


	PrtFile.close();

	if (operatorManager.getSSH() == SS)
	{
		this->LOGIN = true;
		cout <<"管理员 " <<operatorManager.getName()<<" 登录成功" << endl;
		return 1;
	}

	else
	{
		cout << "管理员个人密钥错误,请进行检查";
		return 0;
	}

}

bool Handler::getStatus() 
{
	return this->LOGIN;						//查询Login状态
}


void Handler::addSTD()

{
	OperateSTD operateSTD;
	operateSTD.getInfoFromScreen();
	operateSTD.saveThisFile();
}

void Handler::addTEA()
{
	OperateTEA operateTEA;
	operateTEA.getInfoFromScreen();
	operateTEA.saveThisFile();
}

void Handler::addTAB() 
{
	OperateTable operateTab;
	operateTab.getTableFromScreen();
	operateTab.saveThisFile();
}

void Handler:: addToll() 
{
	TollMenu toll(this->operatorManager);
	toll.display();
}

void Handler:: setTable() 
{
	OperateTable operateTab;
	operateTab.updateThisTable();

}

void Handler:: changeMAGSSH() 
{
	this->operatorManager.setSSH();
	cout << "修 改 管 理 员 " << this->operatorManager.getName();
	cout << " 的 密 钥 成 功 !!! " << endl;
}

void Handler::addVio() 
{
	ViolationMenu Vio(this->operatorManager);
	Vio.display();
}

void Handler::addRun() 
{
	RunningMenu running(this->operatorManager);
	running.display();
}

void Handler::showOneRun(int ruler, int small)
{
	QueryRecord QR;
	RunningRecord RUN(QR.getRunningRecord(ruler));

	time_t now;
	int unixTime = (int)time(&now);	int gap = 0;
	gap = unixTime - RUN.getTimeStamp();
	
	if (abs(gap) > 3)
	{

		if (small == 1)
		{
			RUN.shortShow();
		}
		else
		{
			RUN.display();
		}

	}
}

void Handler::showOneToll_S(int ruler, int small) 
{
	QueryRecord QR;
	TransactionRecord Toll(QR.getHidenTransactionRecord(ruler));

	time_t now;
	int unixTime = (int)time(&now);
	int gap = 0;
	gap = unixTime - Toll.getTimeStamp();
	if (abs(gap) > 3)
	{
		if (small == 1)
		{
			Toll.shortShow();
		}
		else
		{
			Toll.display();
		}
	}
	return;
}

void Handler::showOneToll(int ruler, int small) 
{




	QueryRecord QR;
	TransactionRecord Toll(QR.getHidenTransactionRecord(ruler));
	
	time_t now;
	int unixTime = (int)time(&now);
	int gap = 0;
	gap = unixTime - Toll.getTimeStamp();
	
	if (abs(gap) > 3)
	{

		if (small == 1)
		{
			Toll.shortShow();
		}
		else
		{
			Toll.display();
		}

	}
	return;
}

void Handler::showOneVio(int ruler) 
{

	QueryRecord QR;
	ViolationRecord Vio(QR.getViolationRecord(ruler));

	time_t now;
	int unixTime = (int)time(&now);
	int gap = 0;
	gap = unixTime - Vio.getTimeStamp();
	if(abs(gap)>3)
	{
	Vio.display();
	}
	return;
}

bool Handler::checkSSH() 

{
	string ssh;
	cout << "当前管理员是 " << this->operatorManager.getName() << endl;
	cout << "请输入您的密钥 :  ";
	ssh = getStringWithoutShow();
	return this->operatorManager.checkSSH(ssh);


}

void Handler::showAllTEA()
{

	PerInfo PI("TotalTeacher");//创建人信息保存地址

	ifstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::in);

	if (!perFile)
	{
		cout << "教师信息总文件打开失败，请检查路径是否正确！" << endl;

		cout << "当前路径" << PI.getCompleteAddress() << endl;

	}
	Teacher teacher;
	int i = 1;
	perFile.read((char*)&teacher, sizeof(teacher));
	if (perFile.eof())
	{
		cout << "没有教师记录可供查询，请您先添加教师信息 !!!!" << endl;
		return;
	}

	while (!perFile.eof()) 
	{

		teacher.display();
		cout << endl;
		i++;
		if (i % 2 == 0) 
		{
			cout << "任意按键将进行清屏操作" << endl;
			system("pause");
			system("cls");
		}
		perFile.read((char*)&teacher, sizeof(teacher));
	}
	perFile.close();
	return ;
}


void Handler::shouwAllSTD() 

{
	PerInfo PI("TotalStudent");//创建人信息保存地址

	ifstream perFile;

	perFile.open(PI.getCompleteAddress(), ios::binary | ios::in);

	if (!perFile)
	{
		cout << "学生信息总文件打开失败，请检查路径是否正确！" << endl;

		cout << "当前路径" << PI.getCompleteAddress() << endl;

	}
	Student student;
	int i = 1;

	perFile.read((char*)&student, sizeof(student));
	if (perFile.eof()) 
	{
		cout << "没有学生记录可供查询，请您先添加学生信息 !!!!" << endl;
		return;
	}

	while (!perFile.eof())
	{
		
		student.display();
		cout << endl;
		i++;

		if (i % 2 == 0)
		{
			cout << "任意按键将进行清屏操作" << endl;
			system("pause");
			system("cls");
		}
		
		perFile.read((char*)&student, sizeof(student));
	}

	perFile.close();
	return;
}


float  Handler::checkSummery( int show)    //这是总账的函数，show是是否简要的展示交易记录 
{
	Manager temp;
	Student test;
	Date d;
	TransactionRecord Transaction(temp, test);
	float summery = 0;
	
	RecordInfo ADD("TransactionRecord");
	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "Warning 交易文件打开失败  " << endl;
		cout << "请检查是否存在路径" << ADD.getCompleteAddress() << endl;
		throw 4558;
	}
	
	file.read((char*)&Transaction, sizeof(Transaction));//第一次读取

	if (file.eof())				//读取失败则返回summery
	{
		file.close();
		cout << "暂时没有交易记录可供总账 ！！！" << endl;
		return summery;
	}

	summery += Transaction.getPayment();

	if (show == 1)
	{
		Transaction.shortShow();
	}

	while (!file.eof()) 
	{
		file.read((char*)&Transaction, sizeof(Transaction));

		if (file.eof())
		{
			file.close();
			return summery;
		}
		summery += Transaction.getPayment();

		if (show==1) 
		{
			Transaction.shortShow();
		}
	
	}
	
	file.close();

	return summery;

}


void Handler::showAllRun(int small) 
{


	Manager temp;
	RunningRecord Running(temp, 0, "test");


	RecordInfo ADD("RunningRecord");

	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::binary | ios::in);

	if (!file)
	{
		cout << "Warning 流水记录文件打开失败  " << endl;
		cout << "请检查是否存在路径" << ADD.getCompleteAddress() << endl;
		throw 4585;
	}

	file.read((char*)&Running, sizeof(Running));

	if (file.eof()) 
	{
		cout << "没有流水记录可供查询!!! " << endl;
		return;
	}

	while (!file.eof())
	{
		if (small == 1)
		{
			Running.shortShow();
		}
		else
		{
			Running.display();
		}

		file.read((char*)&Running, sizeof(Running));
	}
	
	file.close();
	return;
}

void Handler::showAllVio( ) 

{
	Manager temp;
	Teacher test;
	Date d;
	ViolationRecord Violation(temp, test, 0, 0, d, "test");


	RecordInfo ADD("ViolationRecord");
	ifstream file;

	file.open(ADD.getCompleteAddress(), ios::in | ios::binary);

	if (!file)
	{
		cout << "Warning 记录文件打开失败  " << endl;
		cout << "请检查是否存在路径" << ADD.getCompleteAddress() << endl;
		throw 4558;
	}
	

	file.read((char*)&Violation, sizeof(Violation));

	if (file.eof()) 
	{
		cout << "没有教学事故记录可供查询!!! " << endl;
		return;
	}

	while (!file.eof()) 
	{
		Violation.display();

		file.read((char*)&Violation, sizeof(Violation));
	}

	file.close();

	return ;
}

void Handler::showAllToll(int small) 
{
	Manager temp;
	Student test;
	Date d;
	TransactionRecord Transaction(temp, test);


	RecordInfo SUM;
	ifstream file2;

	file2.open(SUM.getCompleteAddress(), ios::in | ios::binary);

	if (!file2)
	{
		cout << "Warning 交易文件打开失败  " << endl;
		cout << "请检查是否存在路径" << SUM.getCompleteAddress() << endl;
		throw 4558;
	}
	
	file2.read((char*)&Transaction, sizeof(Transaction));

	if (file2.eof()) 
	{
		cout << "没有交易记录可供查询!!! " << endl;
	}
	while (!file2.eof())
	{
		if (small == 1)
		{
			Transaction.shortShow();
		}
		else
		{
			Transaction.display();
		}

		file2.read((char*)&Transaction, sizeof(Transaction));
	
	}
	
	file2.close();
}
