////P8792 [蓝桥杯 2022 国 A] 最大公约数
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <functional>
//using namespace std;
//
//#define N 1234567
//
//long long gcd(long long a, long long b)
//{
//	if (b == 0)return a;
//	return gcd(b, a % b);
//}
//
//long long arr[N];
//long long n;
//long long cnt = 0;
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		scanf("%lld", &arr[i]);
//		if (arr[i] == 1)
//		{
//			cnt++;
//		}
//	}
//
//	if (cnt)
//	{
//		cout << n - cnt;
//		return 0;
//	}
//	long long ret = 1e9;
//	//枚举左端点
//	for (int i = 0; i < n-1; ++i)
//	{
//		long long x = arr[i];
//		long long len = 0;
//		for (int j = i+1; j < n; ++j)
//		{
//			len++;
//			x = gcd(x, arr[j]);
//			if (x == 1)
//			{
//				ret = min(ret, len);
//				break;
//			}
//		}
//	}
//
//	if (ret == 1e9)
//	{
//		cout << -1;
//	}
//	else
//	{
//		cout << n + ret - 1;
//	}
//	return 0;
//}