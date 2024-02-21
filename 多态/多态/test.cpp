#include <iostream>
using namespace std;

//1.虚函数的重写(重写实现，不改参数和缺省值)  三同（函数名，参数，返回值),例外(称为协变)，返回值可以不同，但必须是父子关系指针或引用
//2.父类指针或引用去调用

//class Person
//{
//public:
//	virtual Person* BuyTicket() 
//	{ 
//		cout << "全价票" << endl;
//		return this;
//	}
//
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student :public Person
//{
//public:
//	virtual Student* BuyTicket() 
//	{ 
//		cout << "打折价票" << endl; 
//		return this;
//	}
//
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//void Func(Person& p)
//{
//	//1.不满足多态 -- 看调用者类型
//	//2.满足多态 -- 看指向的对象类型
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student stu;
//
//	Func(p);
//	Func(stu);
//
//	auto pPerson = new Person;
//	auto pStu = new Student;
//
//	cout << "=======================" << endl;
//	delete pPerson;
//	delete pStu;
//	cout << "=======================" << endl;
//
//	return 0;
//}


//class A
//{
//public:
//	virtual void func(int val = 2556) { cout << "A->" << val << endl; }
//	virtual void test() { func(); };
//};
//
//class B:public A 
//{
//public:
//	void func(int val = 0) { cout << "B->" << val << endl; }
//};
//
//int main()
//{
//	B* p = new B;
//	p->test();
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 2556) { cout << "A->" << val << endl; }
//};
//
//class B :public A
//{
//public:
//	virtual void func(int val = 0) { cout << "B->" << val << endl; }
//	virtual void test() { func(); };
//
//};
//
//int main()
//{
//	B* p = new B;
//	p->test();
//
//	return 0;
//}



//抽象类

//class car
//{
//public:
//	virtual void drive() = 0;
//};