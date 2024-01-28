#define  _CRT_SECURE_NO_WARNINGS 1

#include "func.h"
using namespace std;
//class A
//{
//private:
//	int _a;
//};
//
//template<class T>
//void mySawp(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}

//Ä£°åÌØ»¯
//template<>
//void mySwap<A*>(A* p1, A* p2)
//{
//	std::swap(*p1, *p2);
//}

template <class T>
T func(T a, T b);


int main()
{
	cout << func(1, 2);
	return 0;
}