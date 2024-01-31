//#include <iostream>
//#include <string>
//
//using namespace std;
////基类、父类
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const string& name)
//		:_name(name)
//	{
//		;
//	}
//
//	~Person()
//	{
//		cout << "~Person()"<<endl;
//	}
//
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "张三";
//	int _age = 18;
//};
//
//class Student :public Person
//{
//public:
//	Student()
//	{
//		;
//	}
//
//	Student(const string& name, int stuid)
//		:Person(name)
//		,_stuid(stuid)
//	{
//		;
//	}
//
//	Student& operator=(const Student& stu)
//	{
//		cout << "operator" << endl;
//		if (this != &stu)
//		{
//			Person::operator=(stu);
//			_stuid = stu._stuid;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		Person::~Person();
//		cout << "~Stu()"<<endl;
//	}
//protected:
//	int _stuid = 0;
//};
//
//class Teacher :public Person
//{
//public:
//
//protected:
//	int _jobid;
//};
//
//class Assistant : public Student, public Teacher
//{
//
//};
//
//
//int main()
//{
//	Student stu;
//	stu.Print();
//
//	return 0;
//}

#include <iostream>

class A
{
public:
	int _a = 1;
};

class B :virtual public A
{
public:
	int _b =2;
};

class C :virtual public A
{
public:
	int _c = 3;
};

class D :public B, public C
{
public:
	int _d = 4;
};

int main()
{
	D d1, d2;
	return 0;
}