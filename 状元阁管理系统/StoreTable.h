#ifndef  STORETABLE_H_
#define STORETABLE_H_
#include "Table.h"
#include "Lesson.h"
#include "TabNum.h"

class StoreTable 

	//因为Table使用优先队列实现的，不能存入文件
	//这个类型的对象用于储存在文件中 
	//这两个类互为友元类，方便互相初始化

{
protected:

	char ownerName[20];			//所有者姓名
	int ownerID;				//所有者ID

	char selfName[50];
	char theOtherName[30];
	
	Lesson lessonTable[100];			//课表数组
	
	int num;							//课程数
	int classType;

	int tableID;						//课表编号

	
public:

	friend class Table;
	
	~StoreTable();

	StoreTable();

	StoreTable(const StoreTable& );

	StoreTable( Table  );

	void buildStoreTable( Table );
	
	void setOtherName(string name);

	int getNum();

	Lesson* getLessonTable();

	string GetTheOtherName();

	int getClassType();

	void setTableID();					//更改课表的编号，在存入文件的时候更改

	void setTableID( const  StoreTable &);
};

#endif // ! STORETABLE_H_
