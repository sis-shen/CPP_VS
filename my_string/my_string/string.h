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
			assert(n > _capacity);
			char* tmp = new char[n+1];
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
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void append(const string& s)
		{
			if (_capacity < _size + s._size)
			{
				reserve(_size + s._size + 1);
			}

		}

		void resize(size_t size, const char ch = '\0')
		{
			if (size <= _size)
			{
				_size = size;
				_str[_size] = '\0';
			}
			else 
			{
				if (size > _capacity)
				{
					_capacity = size;
					reserve(_capacity);
				}

				for (int i = _size; i < size; i++)
				{
					_str[i] = ch;
					++i;
				}

				_size = size;
				_str[_size] = '\0';
				
			}
		}

		bool operator==(const string& s) const
		{
			const char* ptr1 = _str;
			const char* ptr2 = s._str;
			while (*ptr1 != '\0' && *ptr1 != '\0')
			{

			}
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}

		void Insert(size_t pos,const char ch)
		{
			if (_capacity <= pos)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;//'\0'也拷贝掉了

			while (end > pos)
			{
				_str[end] = _str[end - 1];
			}

			_str[pos] = ch;
		}

		string& operator+=(const string& s)
		{
			append(s);
			return *this;
		}

		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
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
			dst[cur] = res[cur];//加入\0结尾;
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

	const static size_t npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			cout << ch;
		}
		cout << endl;
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}


		return in;
	}

}

