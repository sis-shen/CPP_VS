//#include <vector>
//#include <iostream>
//#include <functional>
//
//using namespace std;
//
//int main()
//{
//	int N = 0;
//	cin >> N;
//	while (N--)
//	{
//		vector<int> arr;
//		int n, k;
//		cin >> n >> k;
//		int ma = 0;
//		int sum = 0;
//		for (int i = 0; i < k; i++)
//		{
//			int num;
//			cin >> num;
//			sum += num * 2 - 1;
//			ma = max(num, ma);
//			arr.push_back(num);
//		}
//
//		sum -= (ma * 2 - 1);
//		cout << sum << endl;
//	}
//	return 0;
//}