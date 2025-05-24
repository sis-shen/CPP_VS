////#include "color.h"
////
//void lock(int& mtx);
//void unlock(int& mtx);
//
//class RWLock
//{
//public:
//	void RLock()
//	{
//		lock(_rmtx);//获取读锁，使对_rcnt的访问互斥
//		_rcnt++;//引用计数
//		if (_rcnt == 1)
//		{
//			lock(_wmtx);//第一次读锁会获取写锁，阻塞写
//		}
//		unlock(_rmtx);//防止阻塞读
//	}
//	void WLock()
//	{
//		lock(_rmtx);//这一行可选，加了就是读写公平锁,不加就是读优先锁
//		lock(_wmtx);//阻塞其它读写
//	}
//
//private:
//	int _rcnt;
//	int _rmtx;
//	int _wmtx;
//};
//
//
//int main()
//{
//	std::cout << ColorConfig::getInstance();
//	//ColorConfig::print();
//	return 0;
//}


//#include <iostream>
//
//int main()
//{
//	int a = 0x12345678;
//	int arr[10] = { 0 };
//	return 0;
//};

#include <iostream>
#include <string>

using namespace std;

#include "aaa.h"
#include "sub.h"
int main()
{
	string ret = "";
	//cout << ret.empty();
	cout << var;
	return 0;
}