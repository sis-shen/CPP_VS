#define  _CRT_SECURE_NO_WARNINGS 1

//using namespace std; //只影响使用，不影响生命周期
//
//int main()
//{
//	cout << "hello c++ world" <<endl ;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;//项目中禁止全局展开
//
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//
//
//
//
//
//using std::cout;//常用展开
////using std::endl;//常用展开
//
//int main()
//{
//	Func();
//
//	return 0;
//}



#include "Test.h"

void test::add(int a, int b)
{
	std::cout << a + b << std::endl;
}
