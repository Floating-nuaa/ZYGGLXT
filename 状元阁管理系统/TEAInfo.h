#ifndef  TEAINFO_H_
#define TEAINFO_H_
#include "STDInfo.h"
class TEAInfo :public STDInfo 
	
	//老师文件类，是学生文件类的派生类
	//没有什么逻辑关系，就是开发先后的关系
	//主要是不用重写代码了
{
public:

	TEAInfo(string Name);//只需把这个重写一下
	
	TEAInfo();//当然这个也得重写一下
	~TEAInfo();
};
#endif // ! TEAINFO_H_
