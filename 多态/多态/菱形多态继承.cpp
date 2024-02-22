#include <iostream>
using namespace std;


class A
{
public:
	virtual void func1() { cout << "A::func1()" << endl; }

public:
	int _a;
};

class B :public A
{
public:
	virtual void func1() { cout << "B::func1()" << endl; }

public:
	int _b;
};

class C :public A
{
public:
	virtual void func1() { cout << "C::func1()" << endl; }

public:
	int _c;
};

class D :public B, public C
{
public:
	virtual void func1() { cout << "D::func1()" << endl; }//func1±ØÐëÖØÐ´

public:
	int _d;

};