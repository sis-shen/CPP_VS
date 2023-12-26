#pragma once
#include <iostream>
#include <cassert>
using namespace std;

namespace mine
{
	const static size_t npos = -1;


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
			delete[] _str;
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

				for (size_t i = _size; i < size; i++)
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
			return strcmp(_str, s._str) == 0;
		}

		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator<(const string& s) const
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator>=(const string& s) const
		{
			return !(strcmp(_str, s._str) < 0);
		}

		bool operator<=(const string& s) const
		{
			return !(strcmp(_str, s._str) > 0);
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}

		void insert(size_t pos,const char ch)
		{
			assert(pos >= 0 && pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;//'\0'也拷贝掉了

			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++_size;
		}

		void insert(size_t pos, const string& s)
		{
			assert(pos >= 0 && pos <= _size);
			if (_capacity < _size + s._size)
			{
				reserve(_size + s._size);
			}

			size_t len = s._size;
			size_t end = _size + len;
			while (end > pos)
			{
				_str[end] = _str[end - len];
				--end;
			}

			size_t cur_this = pos;
			size_t cur_s = 0;
			while (cur_s < s._size)
			{
				_str[cur_this++] = s._str[cur_s++];
			}

			_size += s._size;

		}

		void erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos >= 0 && pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size = _size - len;
			}
			
		}

		void erase(iterator first, iterator last)
		{
			size_t len = last - first;
			iterator start = _str;
			size_t pos = first - start;
			erase(pos, len);
		}

		void erase(iterator pos)
		{
			while (pos != end())
			{
				*pos = *(pos + 1);
			}
			*pos = '\0';
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

	private:

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

		int strcmp(const char* s1, const char* s2) const
		{
			while (1)
			{
				if (*s1 != *s2)
				{
					return *s1 - *s2;
				}
				else if (*s1 == '\0' && *s2 == '\0')
				{
					return 0;
				}
			}
		}
	};


	//========================
	void test1()
	{
		mine::string s("hello");
		cout << s.c_str() << endl;

		s += " world";
		cout << s.c_str() << endl;
		s[0] = '8';

	}

	void test2()
	{
		mine::string s("hello");
		s.insert(5, ' ');
		s.insert(6, "world");

		s.erase(6, 20);
		cout << s.c_str() << endl;
		s.erase();
		cout << s.c_str() << endl;
		cout << "end";
	}


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

