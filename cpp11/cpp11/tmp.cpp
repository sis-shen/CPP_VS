#include <iostream>

using namespace std;

//计算
template <unsigned N>
static int to_sum()
{
	return to_sum<N - 1>() + N;
}

template <>
static int to_sum<1>()
{
	return 1;
}

// 类型萃取
template <class T>
struct my_is_pointer {
	static constexpr bool value = false;
};

template <class T>
struct my_is_pointer<T*> {
	static constexpr bool value = true;
};

// 类型判断
template <class T, class U>
struct my_is_same {
	static constexpr bool value = false;
};

template <class T>
struct my_is_same<T, T> {
	static constexpr bool value = true;
};

// 移除const
template <class T>
struct my_remove_const {
	using type = T;
};

template <class T>
struct my_remove_const<const T> {
	using type = T;
};
int main()
{
	cout << to_sum<5>() << endl;
	cout << my_is_pointer<int>::value << endl;
	cout << my_is_same<int, int>::value << endl;
	cout << my_is_same<int, const int>::value << endl;
	cout << my_is_same<int, my_remove_const<const int>::type>::value << endl;
	return 0;
}