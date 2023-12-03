#define  _CRT_SECURE_NO_WARNINGS 1

#include "Test.h"

#define ADD(x,y) ((x)+(y))

//КЏЪ§жиди
int Add(int a, int b)
{
	return a + b;
 }

double Add(double a, double b)
{
	return a + b;
}

void print(char a, int b)
{
	std::cout << a << " " << b << std::endl;
}

void print(int a, char b)
{
	std::cout << a << " " << b << std::endl;
}


int main()
{

	test::add(1,2);
	return 0;
}