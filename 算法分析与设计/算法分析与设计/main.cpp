//#include <iostream>
//#include <set>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		set<int> hash;
//
//		for (int i = 0; i < n; ++i)
//		{
//			int num;
//			cin >> num;
//			num += 1;
//			hash.insert(num/2);
//		}
//		vector<int> arr;
//		for (auto num : hash)
//		{
//			arr.push_back(num);
//		}
//		sort(arr.begin(), arr.end());
//		long long sum = 0;
//		long long ret = arr[0];
//
//		for (int i = 1; i < arr.size(); ++i)
//		{
//			if (arr[i] - arr[i - 1] <= 1) continue;
//			else
//			{
//				ret += arr[i] - arr[i - 1] - 1;
//			}
//		}
//
//
//		cout << ret <<endl;
//
//	}
//	
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int trans(int a)         //对每个血量转换成其所需的子弹数
//{
//	if (a % 2 == 0) return a / 2;
//	else
//	{
//		return a / 2 + 1;
//	}
//}
//int n;
//int a[10005];
//int main()
//{
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			int b;
//			scanf("%d", &b);
//			a[i] = trans(b);
//		}
//		sort(a + 1, a + 1 + n);         //调用sort函数，对所需子弹数进行升序排序
//		int ans = 0;
//		ans += a[1];               //第一部分，即打死最少血量敌人所需的子弹数
//		for (int i = 1; i <= n; i++)
//		{
//			if (i == 1 || a[i] - a[i - 1] == 0 || a[i] - a[i - 1] == 1) continue;
//			else ans += a[i] - a[i - 1] - 1;   
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}


 //1031

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{	
	int n;
	while (cin >> n)
	{
		vector<vector<int >> arr(n+1, vector<int>(n+1, 0));
		auto dp(arr);

		for (int i = 0; i <n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
			}
		}
		cout << dp[0][0] <<endl;
	}


	return 0;
}

//1039

#include <vector> 
#include <iostream>
#include <algorithm>