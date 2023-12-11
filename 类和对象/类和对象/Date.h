#pragma once
#include <iostream>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date();
	Date(int year, int month, int day);
	Date(const Date& d);
	int GetYear() const;
	int GetMonth() const;
	int GetDay()const;

	void print() const;
	int GetMonthDay(int year, int month)const;
	Date Add(int x) ;
	Date& AddEqual(int x);
	bool operator==(const Date& d2) const;
	bool operator>(const Date& d2) const;
	bool operator<(const Date& d2) const;
	bool operator>=(const Date& d2) const;
	bool operator<=(const Date& d2) const;
	bool operator!=(const Date d2) const;
	Date& operator+=(int x);
	Date operator+(int x) const;
	Date& operator-=(int day);
	Date operator-(int day) const;
	Date& operator++();
	Date operator++(int);
	int operator-(const Date& date) const;

private:
	int _year = 0;
	int _month = 0;
	int _day = 0;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, const Date& d);