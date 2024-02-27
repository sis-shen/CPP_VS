#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class Maxtrix
{
	typedef vector<vector<T>> MT;
public:
	Maxtrix()
		:_matrix(nullptr)
	{
		;
	}
	Maxtrix(int m,int n)//ππ‘Ï0æÿ’Û
	{
		_matrix = new MT(m, n);
		_m = m;
		_n = n;
	}
	Maxtrix(const MT& mt)
	{
		_matrix = new MT(mt);
		_m = mt._m;
		_n = mt._n;
	}
	Maxtrix(Maxtrix mt)
	{
		swap(_matrix, mt._matrix);
	}
	~Maxtrix()
	{
		delete _matrix;
		_matrix = nullptr;
	}

	Matrix& operator+(const Matrix& mt)
	{
		if()
	}
private:
	MT* _matrix;
	size_t _m = 0;
	size_t _n = 0;
};