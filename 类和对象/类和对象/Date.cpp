#define  _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"


using namespace std;



Date::Date()//构建函数
	:_year(0)
	,_day(0)
	,_month(0)
{

}

Date::Date(int year, int month, int day)//可以重载
{
	if (day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		std::cout << "非法日期" << std::endl;
	}
}

//拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	this->_day = d._day;
}


int Date::GetYear() const
{
	return _year;
}

int Date::GetMonth() const
{
	return _month;
}

int Date::GetDay() const
{
	return _day;
}


int Date::GetMonthDay(int year, int month) const
{
	if (month <= 0 || month >= 13)
	{
		return 0;
	}

	int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		monthArray[2]++;
	}
	return monthArray[month];
}

//+
Date Date::Add(int x)
{
	//Date tmp = *this;//或者
	Date tmp(*this);

	tmp._day += x;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			tmp._month = 1;
			tmp._year++;
		}
	}

	return tmp;
}

//+=
//传值返回会调用 拷贝构造， 使用传引用返回减小消耗 
Date& Date::AddEqual(int x)
{
	//Date tmp = *this;//或者
	Date& tmp(*this);

	tmp._day += x;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			tmp._month = 1;
			tmp._year++;
		}
	}

	return tmp;
}

bool Date::operator==(const Date& d2) const
{
	return _year == d2._year && _month == d2._month && _day == d2._day;
}

bool Date::operator<(const Date& d2) const
{
	return _year < d2._year
		|| (_year == d2._year && _month < d2._month)
		|| (_year == d2._year && _month == d2._month && _day < d2._day);
}
bool Date::operator>(const Date& d2) const
{
	return !(*this == d2 || *this < d2);
}
bool Date::operator>=(const Date& d2) const
{
	return !(*this < d2);
}
bool Date::operator<=(const Date& d2) const
{
	return !(*this > d2);
}

bool Date::operator!=(const Date d2) const
{
	return !(*this == d2);
}



Date& Date::operator+=(int x)
{
	if (x < 0)
	{

	}
	Date& tmp = *this;
	tmp._day += x;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			tmp._month = 1;
			tmp._year++;
		}
	}

	return tmp;
}

Date Date::operator+(int x) const
{
	Date tmp(*this);
	tmp += x;
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		if (_month > 1)
		{
			--_month;
			_day += GetMonthDay(_year, _month);
		}
		else
		{
			_year--;
			_month = 12;
			_day += GetMonthDay(_year, _month);
		}
	}
	return *this;
}

Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)//int构成重载,且必须是int,表示是前置++;
{
	Date tmp(*this);

	*this += 1;
	return *this;
}


int Date::operator-(const Date& date) const
{
	Date max = *this;
	Date min = date;

	int flag = 1;

	if (*this < date)
	{
		max = date;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;
}




void Date::print() const
{
	std::cout << _year << ":" << _month << ":" << _day << endl;
}

//////////////////////////////////////////////////////////////
//运算符重载  使自定义类型可以使用运算符

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month>> d._day;
	return in;
}