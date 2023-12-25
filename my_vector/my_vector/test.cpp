#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

#include "vector.h"

void func(sup::vector<int> v)
{
	for (auto num : v)
	{
		cout << num << " ";
	}
	cout << endl;
}

void test1()
{
	sup::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	v1.pop_back();
	v1[1] = 666;

	v1.resize(8, 99);
	func(v1);

	v1.resize(2);
	func(v1);

}


int main()
{
	test1();

	return 0;
}