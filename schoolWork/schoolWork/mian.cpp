//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Course
//{
//public:
//	Course(const string& name,int credit = 0,int id = -1,double score = 0)
//		:_name(name), _credit(credit), _id(id), _score(score)
//	{}
//
//	void Set(const string& name, int credit = 0, int id = -1, double score = 0)
//	{
//		_name = name;
//		_credit = credit;
//		_id = id;
//		_score = score;
//	}
//	void Info()
//	{
//		printf("课程名:%s ,课程号:%d ,学分:%d ,分数:%lf\n", _name.c_str(), _credit, _id, _score);
//	}
//
//	void ShowName()
//	{
//		cout << "课程名:" << _name << endl;
//	}
//
//	void ShowCredit()
//	{
//		cout << "学分：" << _credit << endl;
//	}
//
//	void ShowID()
//	{
//		cout << "课程ID" << _id << endl;
//	}
//
//	void ShowScore()
//	{
//		cout << "分数" << _score << endl;
//	}
//
//private:
//	string _name;
//	int _credit;//学分
//	int _id;//课程号
//	double _score;//分数
//};
//
//
//
//int main()
//{
//	Course CPP("C++程序设计", 3, 1, 99.8);
//	CPP.ShowName();
//	CPP.Info();
//	CPP.Set("C++面向对象", 6, 11, 250);
//	CPP.Info();
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS 1

// 命名空间

//#include <stdio.h>
//#include <stdlib.h>
//
//int rand = 0; // 编译的时候cstdlib全局展开，与rand发生命名冲突
//// 也就是说，我们和库之间会有命名冲突
//// 而在公司里面，一个项目有好多人，很有可能会有命名冲突
//
//int main()
//{
//	printf("%d\n", rand);
//
//	return 0;
//}

// 于是，为了解决命名冲突的问题，就有了命名空间
// 关键字namespace

#include <stdio.h>
#include <stdlib.h>

// 本质上是定义一个命名空间域
namespace tan
{
	int rand = 0;
}

int a = 0;

int main()
{
	printf("%p\n", rand); // 随机值，取到的是库里面的
	printf("%d\n", tan::rand); // 访问的就是全局

	int a = 1;
	printf("%d\n", a);
	printf("%d\n", ::a); // ::域限定符，左边没加默认全局

	return 0;
}