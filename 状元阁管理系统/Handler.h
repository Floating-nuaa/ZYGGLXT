#ifndef HANDLER_H_
#define HANDLER_H_
#include <iostream>
#include "Manager.h"
#include "PerInfo.h"
#include "OperateSTD.h"
#include "OperateTEA.h"
#include "OperateTable.h"
#include "TollMenu.h"
#include "ViolationMenu.h"
#include "RunningMenu.h"
#include "QueryRecord.h"
using namespace std;
class Handler 

	//控制台类，进行权限释放

{
private :
	
	Manager operatorManager;
	bool LOGIN;

public:
	
	Handler();
	~Handler();

	bool LoginManager(string name,string SSH );			//传入姓名和密钥进行登录
	bool getStatus();									//获得登录状态

	void addSTD();										//增加学生，教师，课表
	void addTEA();											
	void addTAB();
	void addToll();										//增加交易记录，流水，违规记录
	void addVio();
	void addRun();
	void setTable();									//修改课表
	void changeMAGSSH();								//修改当前管理员的密钥

	void showOneRun(int ruler,int small );				//传入数据位置参数展示三种记录
	void showOneToll_S(int ruler, int small);
	void showOneVio(int ruler);
	void showOneToll(int ruler, int small);

	void showAllRun(int  );								//展示所有的三种记录
	void showAllVio(  );
	void showAllToll( int );
	
	bool checkSSH();									//某些操作的密码验证

	void showAllTEA();									//展示总表中的教师和学生信息
	void shouwAllSTD();								

	float checkSummery(int show);						//一键总账


};
#endif // !HANDLER_H_

