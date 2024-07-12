#include <iostream>

using namespace std;

//int g_arr[10] = { 0 };
//
//void func(int st_arr[])
//{
//	cout << sizeof(st_arr) << endl;//此处退化为指针变量，输出4或8
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	cout << sizeof(g_arr) << endl;//输出40
//	cout << sizeof(arr) << endl; //输出40
//	func(arr);//输出4/8
//	return 0;
//}

class R
{
	int _a, _b, _c;
};

class A
{
	char _ch;
	short _s;
};

int main()
{
	cout << sizeof(A);
	return 0;
}