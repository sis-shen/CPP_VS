#define  _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <cassert>
using namespace std;


namespace mine
{
class string
{
public:
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
		dst[cur] = res[cur];//¼ÓÈë\0½áÎ²;
		return dst;
	}
};



}

void test1()
{
	mine::string s("hello");
	cout << s.c_str() << endl;

	s += " world";
	cout << s.c_str() << endl;
	s[0] = '8';
	cout << s << endl;

	
}


int main()
{
	test1();

	//char* str = new char[20];
	//delete[] str;

	return 0;
}