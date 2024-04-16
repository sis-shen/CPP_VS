#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
    void Init(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
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
    Date* pd = &d;
    d._num;

    return 0;
}

