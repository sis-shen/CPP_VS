#include <iostream>
#include <string>


struct Employee
{
	std::string name = "Unkown";
	int id = -1;
	double salary = 0.0;
};

int main()
{
	int raw = 10;
	const int& x = raw;
	//这个是变量的声明和初始化
	int y = x;//可以用于变量初始化,x 和 y是不同的对象
	//下面都是引用的声明
	int& z = x;//不可以，因为z是引用，和x指向了同样的对象，但权限放大
	int* n = &x;//同样不可以，还是权限放大
	const int& a = x;//彳亍
	const int* m = &x;//彳亍


	Employee e1;
	Employee e2 = { "Jongh", 1 , 1.0 };
	Employee e3 = { "Web" };
	return 0;
}