//#include <iostream>
//
//using namespace std;
//
//class Base1
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base1::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base1::Func2" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base1::Func3()" << endl;
//	}
//
//private:
//	int _b1 = 1;
//};
//
//class Base2
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base2::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base2::Func2" << endl;
//	}
//
//
//private:
//	int _b2 = 1;
//};
//
//class Derive : public Base1,public Base2
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//
//	virtual void Func4()
//	{
//		cout << "Derive::Func4()" << endl;
//	}
//
//
//private:
//	int _d = 2;
//};
//
////用程序打印虚表
//typedef void(*VF_PTR)();
//
//void PrintVFTable(VF_PTR table[])
//{
//	//VS系列编译器的特性: 虚表以nullptr结尾
//	for (int i = 0; table[i] != nullptr; ++i)
//	{
//		printf("[%d]:%p->", i, table[i]);
//		VF_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}
//
//
//int main()
//{
//	Base1 b;
//	Derive d;
//
//	PrintVFTable((*(VF_PTR**)&d));
//
//	//PrintVFTable((*((VF_PTR**)((char*) & d + sizeof(Base1))) + 1));
//	Base2* ptr = &d;
//	PrintVFTable((*(VF_PTR**)ptr));
//
//
//
//	return 0;
//}