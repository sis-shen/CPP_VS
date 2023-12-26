#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

#include "vector.h"

template <class T>
void func(const sup::vector<T>& v)
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

	auto ptr = v1.begin();
	while (ptr != v1.end())
	{
		if (*ptr == 99)
		{
			ptr = v1.erase(ptr);
		}
		else
		{
			++ptr;
		}
	}
	v1.push_back(6);
	func(v1);

}

void test2()
{
	int arr[] = { 1,3,5,7,9,6,4,5 };
	string s("hello");
	sup::vector<int> v1(6, 6);
	sup::vector<int> v2(arr, arr + 5);
	sup::vector<char> v3(s.begin(), s.end());
	func<int>(v1);
	func<int>(v2);
	func<char>(v3);
}

void test3()
{
	sup::vector<int> v1(6, 9);
	sup::vector<int> v2(v1);
	auto v3(v1);
	
	sup::vector<string> v4(25, "233");

	auto v5(v4);
	func<int>(v1);
	func<int>(v2);
	func<int>(v3);
	func(v4);
	func(v5);

}

void test4()
{
	//≤‚ ‘∂˛Œ¨vector
	vector<vector<int>> vv;
	vv.resize(9, vector<int>());
	
}

int main()
{

	test4();
	return 0;
}