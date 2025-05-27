//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <functional>
//using namespace std;
//
//#define N 1234567
//
//
//long long arr[N];
//long long dp[N];
//long long n;
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//	}
//	dp[0] = arr[0];
//	for (int i = 1; i < n; ++i)
//	{
//		dp[i] = dp[i - 1] + arr[i];
//	}
//	long long ret = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		ret += (dp[n - 1] - dp[i]) * arr[i];
//	}
//
//	cout << ret;
//	return 0;
//}