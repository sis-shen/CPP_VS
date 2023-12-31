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


	sup::list<int> lt2(lt1);
	for (auto e : lt2)
	{
		std::cout << e << "->";
	}


	return 0;
}