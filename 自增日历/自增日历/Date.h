#pragma once

#include <iostream>

using namespace std;
class Date
{
public:

    Date(int year = 2024, int month = 4, int day = 1) : _year(year), _month(month), _day(day) {}

    Date(const Date& date):_year(date._year),_month(date._month),_day(date._day)
    {}

    void Print()
    {
        cout << _year << ":" << _month << ":" << _day << endl;
    }

    //在类的内部,重构一个 ==
public:
    bool operator==(const Date& date) const
    {
        return _year == date._year
            && _month == date._month
            && _day == date._day;
    }

    Date& operator++()
    {
        int correct = 0;
        if (_month == 2 && _isLuner())correct = 1;
        _day++;
        if (_day > v_month[_month] + correct)
        {
            _day -= v_month[_month] + correct;
            _month++;
        }
        if (_month > 12)
        {
            _month -= 12;
            _year++;
        }

        return *this;
    }

    Date operator++(int)
    {
        Date tmp(*this);
        ++(*this);
        return tmp;
    }

private:
    bool _isLuner() //是否是闰年
    {
        if (_year % 400 == 0 || _year % 100 != 0 && _year % 4 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    int v_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

private:
    int _year;
    int _month;
    int _day;
};