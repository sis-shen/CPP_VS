#include <iostream>

using namespace std;

//C++98
class NoCopy
{
private://设置成私有
	NoCopy(const NoCopy&);
	NoCopy& operator=(const NoCopy&);//只声明不定义
};

//C++11
class CopyBan
{
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;
};

class HeapOnly
{
public:
	static HeapOnly* GenerateObj()//提供静态成员函数
	{
		return new HeapOnly();
	}

private:
	HeapOnly();//私有化默认构造函数
	HeapOnly(const HeapOnly&) = delete;//禁掉拷贝构造
	HeapOnly& operator=(const HeapOnly&) = delete;//删除赋值运算重载
};


class StackOnly
{
public:
	static StackOnly CreatObj()
	{
		return StackOnly();//返回临时对象的拷贝
	}

private:
	StackOnly() {}

	StackOnly(const StackOnly&) = delete;

	void* operator new(size_t size) = delete;
	void operator delete(void* ptr) = delete;
};

class NoInherit
{
public:
	static NoInherit GenerateInstance()
	{
		return NoInherit();
	}
private:
	NoInherit() {}
};

class InheritBan final
{

};

int main()
{
	cout << "OK" << endl;
	return 0;
}