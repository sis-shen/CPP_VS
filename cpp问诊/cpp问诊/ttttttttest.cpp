#include <iostream>
using namespace std;

//class X
//{
//public:
//	int _x;
//};
//
//class A
//{
//public:
//	int _a;
//};
//
//class B :public A
//{
//public:
//	int _b;
//};
//
//class C :public B
//{
//public:
//	int _c;
//};
//
//class D :public X, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D* pd = new D;
//	X* px = pd;
//	C* pc = pd;
//
//	A* pa = pd;
//	return 0;
//}

int main()
{
	for (double i = 12.0; i <= 82.0; i += 0.5)
	{
		printf("%.1lf ", i);
	}

	return 0;
}