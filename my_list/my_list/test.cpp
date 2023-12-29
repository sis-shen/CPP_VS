#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include "list.h"

int main()
{
	sup::list<int> lt1;

	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);


	//for (auto e : lt1)
	//{
	//	std::cout << e << ' ';
	//}

	return 0;
}