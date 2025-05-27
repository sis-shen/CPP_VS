//#define _CRT_SECURE_NO_WARNINGS 1
//
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
using namespace std;
int n = 1;

string vc("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");

string toN(int num)
{
	if (num == 0)return "0";
	string ret("");
	while (num)
	{
		ret.push_back(vc[num % n]);
		num /= n;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << toN(i) << "*" << toN(j) << "=" << toN(i * j) << " ";
		}
		cout << endl;
	}

	main();
	return 0;
}