#pragma once

//template<typename T>
//class Singleton {
//private:
//	static T _eton;
//private:
//	Singleton() {}//私有化构造函数
//	~Singleton() {}
//public:
//	Singleton(const Singleton&) = delete;//删除拷贝构造
//	Singleton& operator=(const Singleton&) = delete;//删除赋值运算重载
//	static T& getInstance()
//	{
//		return _eton;
//	}
//};
//
//template<typename T>
//T Singleton<T>::_eton = T();

 //懒汉模式
template <typename T>
class Singleton {
private:
	Singleton() {}
	~Singleton() {}
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static T& getInstance()
	{
		static T _eton=T();
		return _eton;
	}
};