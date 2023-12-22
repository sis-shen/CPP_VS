#pragma once
#include <iostream>
#include <cassert>
using namespace std;

namespace mine
{
	class string
	{
	public:

		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		const_iterator begin() const
		{
			return _str;
		}

		iterator end()
		{
			return _str+_size;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
		{
			delete[] _str;
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		const char* c_str()
		{
			return _str;
		}

		string& operator+=(const string& s)
		{
			char* tmp = new char[_capacity + s._capacity + 1];
			strcpy(tmp, _str);
			strcpy(tmp + _size, s._str);

			delete[] _str;
			_str = tmp;
			_size += s._size;
			_capacity += s._capacity;

			return *this;
		}

		char& operator[](int pos)
		{
			assert(0 <= pos && pos < _size);
			return _str[pos];
		}

		const char& operator[](int pos) const
		{
			assert(0 <= pos && pos < _size);
			return _str[pos];
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		void Print(const string& s)
		{
			cout << _str << endl;
		}

		void reserve(size_t n)
		{
			assert(n >= _capacity);
			char* tmp = new char[n];
			strcpy(tmp,_str);
			delete _str;
			_str = tmp;
		}

		void push_back(char ch)
		{
			if (_size + 1 > _capacity)
			{
				reserve(_capacity * 2);
			}
		}

		void append()
		{

		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		size_t strlen(const char* str)
		{
			size_t cnt = 0;
			while (*str != '\0')
			{
				str++;
				cnt++;
			}
			return cnt;
		}

		char* strcpy(char* dst, const char* res)
		{
			int cur = 0;
			while (res[cur] != '\0')
			{
				dst[cur] = res[cur];
				cur++;
			}
			dst[cur] = res[cur];//º”»Î\0Ω·Œ≤;
			return dst;
		}
	};

	void test1()
	{
		mine::string s("hello");
		cout << s.c_str() << endl;

		s += " world";
		cout << s.c_str() << endl;
		s[0] = '8';

	}

}

