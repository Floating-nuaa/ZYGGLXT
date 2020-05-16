#ifndef  STDAFX_H_
#define STDAFX_H_
#include <string>
#include <map>
using namespace std;


								
bool checkBigPassword(string s);			//检测老大授权码

bool saveAccount(string name, string password); //

bool checkPassword(string input);

bool checkSaveAddress(string);

string getStringWithoutShow();			//不显示屏幕获取字符串

string TimeStampToStandard(int );		//把时间戳转换为标准时间

bool checkToContinue();					//询问是否继续

void operationCancled();				//操作取消

string translateNumToClassType(int);	//代码转为课程类型

char checkGender();						//获取性别

string trnaslateVioCode(int, int);		//违规代码转换为具体事项

#endif


