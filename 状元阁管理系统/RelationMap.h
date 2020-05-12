#ifndef RELATIONMAP_H_
#define RELATIONMAP_H_

/********************************************************************
					RelationMap
	
	这是关系图类，维护一个老师和学会的二维连通图
	就是把老师和学生放在对等的位置，支持双向查找
	这个类的是储存数据的类，只要能在里边修改关系即可
	虽然这个图的数据很稀疏，但目前没有什么好的方法
	最后修改时间 2020/5/12

*********************************************************************/

class RelationMap 

{
private :

	bool MAP[125][125];//假设机构不超过两百个人

public :
	
	RelationMap();
	~RelationMap();
	
	RelationMap(const RelationMap&);
	RelationMap operator =(const RelationMap&);
	
	void display();
	
	void addRelation(int, int);
	void deleteRelation(int, int);
	void updateFile();


};

#endif // !RELATIONMAP_H_



