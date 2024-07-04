#include <iostream>
using namespace std;

//class X
//{
//public:
//	int _x;
//};
//
//class A
//{
//public:
//	int _a;
//};
//
//class B :public A
//{
//public:
//	int _b;
//};
//
//class C :public B
//{
//public:
//	int _c;
//};
//
//class D :public X, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D* pd = new D;
//	X* px = pd;
//	C* pc = pd;
//
//	A* pa = pd;
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

bool isLunarYear(int year)
{
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) return true;
    else return false;
}

vector<int> vmonth0 = { 0,31,28,31,28,31,30,31,31,30,31,30,31 };

int main() {
    int year, ds;
    while (~scanf_s("%d %d", &year, &ds))
    {
        vector<int> vmonth(vmonth0);
        if (isLunarYear(year)) vmonth[2]++;
        int month = 1;
        while (ds > vmonth[month])
        {
            ds -= vmonth[month];
            month++;
        }
        printf("%d-%02d-%02d\n", year, month, ds);
    }
}