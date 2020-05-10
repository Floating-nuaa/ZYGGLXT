#ifndef  STDINFO_H_
#define STDINFO_H_
#include <string>
#include "BaseFile.h"

class  STDInfo : public BaseFile 

	//这是学生信息文件类
	//有保存位置和数据类型，也是文件类型
{

public:

	STDInfo(string Name);
	
	STDInfo();
	
	STDInfo(const STDInfo&);

	virtual ~STDInfo();


	STDInfo operator = (const STDInfo&);

	void setName(string Name);


};
#endif // ! STDINFO_H_

