#ifndef RUNNINGRECORD_H_
#define RUNNINGRECORD_H_
#include "Record.h"
#include <string>
#include "stdafx.h"
using namespace std;

/**************************************************************
	类型说明
	店内流水账类，主要记录店内日常开销，比如购买水性笔，桶装水等
	需要记录信息 操作人员（Manager 或者 Teacher ） 
***************************************************************/

class RunningRecord :public Record 

{
protected:

	float payment;			// 此次费用
	char collectWay[20];	// 支付方式
	char remarks[100];		//用途备注
	char payer[30];			//支付者说明，是否是管理员本人

public:

	RunningRecord(Manager&, float pay, string Remarks
		, string payer = "管理员本人", string collect = "微信支付");

	~RunningRecord();
	

	RunningRecord(const RunningRecord&);

	RunningRecord operator= (const RunningRecord&);
	
	//重载一个赋值号


	void display();
	void shortShow();

};
#endif // !RUNNINGRECORD_H_
