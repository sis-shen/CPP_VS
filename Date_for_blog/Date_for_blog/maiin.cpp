#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
    Date(int year = 1,int month = 1,int day = 1):_year(year),_month(month),_day(day)
        {}

    void TestPrint()
    {
        _year = 2024;//隐式调用this访问成员变量
        this->_month = 4;//显式调用this
        _day = 1;
        Print();//隐式调用this来调用成员函数Print()
        this->Print();//显式调用this，效果与上一句相同
    }

    void Print()
    {
        cout << _year << ":" << _month << ":" << _day << endl;
    }

protected:
    int _num;

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d;

    d.TestPrint();
    return 0;
}

