//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	priority_queue<int,vector<int>,greater<int>> minq;
//	while (n--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		minq.push(a); minq.push(b); minq.push(c);
//		for (int i = 0; i < 5; i++)
//		{
//			int num = minq.top(); minq.pop();
//			num++;
//			minq.push(num);
//		}
//		a = minq.top(); minq.pop();
//		b = minq.top(); minq.pop();
//		c = minq.top(); minq.pop();
//		cout << a * b * c<<endl;
//
//	}
//
//	return 0;
//}