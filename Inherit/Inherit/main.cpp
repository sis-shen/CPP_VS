//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	void Info()
//	{
//		printf("name:%s age:%d\n", _name.c_str(), _age);
//	}
//protected:
//	string _name = "supdriver";
//	int _age = 24;
//};
//
//class Student:public Person
//{
//public:
//	void getID()
//	{
//		cout << "ID:" << _ID << endl;
//	}
//private:
//	int _ID = 114514;
//};
//
//
//int main()
//{
//	Student stu;
//	stu.Info();
//	stu.getID();
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	//基类的公有构造函数
//	Person(const string& name, const string& gender, int age)
//		:_name(name)
//		,_gender(gender)
//		,_age(age)
//	{}
//	void Info()
//	{
//		printf("name:%s age:%d\n", _name.c_str(), _age);
//	}
//protected:
//	string _name;
//	string _gender;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	Student(const string& name,const string& gender,int age,int ID)
//		:Person(name,gender,age)//显式调用父类的构造函数
//		,_ID(ID)
//	{}
//	void getID()
//	{
//		cout << "ID:" << _ID << endl;
//	}
//public:
//	int _ID;
//};
//
//
//int main()
//{
//	Student stu("supdriver", "male", 24, 114514);//调用构造函数
//
//	Person  person(stu);//这里没有显式声明对应的构造函数，而是自动切片
//	Person* pp = &stu;//父类指针可以指向派生类
//	Person& rp = stu;//父类引用可以指向派生类
//
//	//stu = person;//父类对象不能赋值给派生类
//
//	//基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &stu;
//	Student* pstu = (Student*)pp;//指针地址就是指向派生类的，所以这种情况是安全的，合法的
//	pstu->_ID = 233;//这里并没有越界
//
//	pp = &person;
//	pstu = (Student*)pp;//这种就是不安全的，可能会越界访问	
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	void Info()
//	{
//		printf("name:%s age:%d\n", _name.c_str(), _age);
//	}
//protected:
//	string _name = "supdriver";
//	int _age = 24;
//};
//
//class Student:public Person
//{
//public:
//	void Info()//同名函数构成隐藏
//	{
//		printf("name:%s age:%d\n ID:%d", _name.c_str(), _age,_ID);
//	}
//private:
//	int _ID = 114514;
//};
//
//
//int main()
//{
//	Student stu;
//	stu.Info();//调用Student类内的Info函数，而父类内的被隐藏
//	stu.Person::Info();//显式调用Person内的Info函数
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._name << endl;//这行代码不会报错，因为_name是继承自Person类的
//	cout << s._stuNum << endl;//这行代码会报错，因为函数没有权限访问Student类自己声明的成员
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 静态成员变量,统计人的个数。
//};
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//	return 0;
//}

class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}


