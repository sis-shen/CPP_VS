#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		_arr = (int*)malloc(sizeof(int) * _sz);
	}


private:
	int* _arr =NULL;
	int _sz = 8;
};


class Stack
{
public:
	Stack()
	{
		_a = new int[_capacity];
	}

	~Stack()
	{
		delete[] _a;
	}

private:
	int* _a = NULL;
	int _capacity = 8;
	int _top = 0;
};

int main()
{
	int* p1 = new int;
	int* p2 = new int(10);//用10初始化
	int* p3 = new int[10];//申请数组
	int* p4 = new int[10] {0};

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;

	A* p5 = new A;
	delete p5;
	return 0;
}