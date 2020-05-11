#ifndef BASEFILE_H_
#define BASEFILE_H_
#include <string>
#include <fstream>
using namespace std;

class BaseFile 

	//创建基础文件类，是所有文件类的基类
	//文件绝对路径= saveAddress+uniqueAddress+fileName
	//功能文件夹，按照文件的种类进行分类

{

private:

	static string REGISTERADDRESS;//储存的绝对路径，只会出现在参数列表里
	static void RESETADDRESS(string);//修改绝对路径

protected :
	
	const string saveAddress;//储存位置,绝对路径，到位置文件夹,一般不进行修改
	string uniqueAddress;//功能文件夹
	string fileName;//文件的名称
	string completeFile;//把前三个整合到一起，这是为了方便调用

public :
	
	BaseFile();

	BaseFile(string UA, string FA);	//第一个参数是功能描述uniqueAddress，第二个参数是文件名称filename

	BaseFile(const BaseFile&);
	
	BaseFile operator=(const BaseFile&);

	string getCompleteAddress();

	string getSaveAddress();

	string getfileName();

	void setFileName(string FA);//参数是filename

	void changeSaveAddress();//改变储存的位置，需要验证密码

	void display();

	virtual ~BaseFile(){}

	//virtual bool saveThisFile();
};

#endif // !BASEFILE_H_

