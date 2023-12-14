#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

template<class T>
void Sawp(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}



int main()
{
	return 0;
}