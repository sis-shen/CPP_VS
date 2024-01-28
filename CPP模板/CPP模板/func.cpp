#include "func.h"

template <class T>
T func(T& a, T& b)
{
	return a+b;
}


template
int func<int>(int& a, int& b);