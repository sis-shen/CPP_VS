#define  _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

//class B
//{
//public:
//	B()
//	{
//		cout << "B()" << endl;
//	}
//
//private:
//	int _a;
//};
//
//
//class A
//{
//public:
//	A()
//		: _x(233)//初始化列表
//		, ref(_a1)
//		, _a1(5)
//		, _bb()
//	{
//
//	}
//
//	explicit A(int x) //不允许隐式类型转换   !!!!!!
//		: _x(233)
//		, ref(_a1)
//		, _a1(x)
//		, _bb()
//	{
//
//	}
//
//private:
//	int _a1 = 1;
//	int _b;
//	const int _x;
//	int& ref;
//	B _bb;
//};
//
//
//int main()
//{
//	Date d1(2023, 9, 8);
//	Date d2(2023, 12, 6);
//
//	int day1 = d1 - d2;
//	int day2 = d2 - d1;
//
//	void* pd = &d1;
//
//	A aa;
//
//	A aa(1);
//	A a2 = 1;//隐式类型转换
//	
//	return 0;
//}


//实现一个类，计算程序中创建了多少个类

class A
{
public:
	A()
	{
		count++;
	}

	A(const A& aa)
	{
		count++;
	}

	int GetCount() const
	{
		return count;
	}

	//静态成员函数 --没有this指针 
	static int STGetCount()
	{
		return count;
	}
private:
	//静态成员，不属于某个静态成员，属于整个类
	static int count;


public:
	class C
	{

	};
};

int A::count = 0;



int main()
{
	A aa;

	cout << A::STGetCount() << endl;
	A* ptr = nullptr;
	cout << ptr->GetCount() << endl;



	return 0;
}





