#define  _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	for (int i = 1; i <= 2000; i++)
//	{
//		string a = to_string(i);
//		cout << a << endl;
//	}
//
//	return 0;
//}

#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	long long sum = 0;
	for (int i = 1; i <= 2020; i++)
	{
		string a(to_string(i));
		for (int j = 0; j < a.size(); j++)
		{
			//if(a[j] =='2' || a[j] == '0')
			//cout << a[j] << endl;
			char ch = a[j];
			if (a[j] == '2' /*|| a[j] == '0' || a[j] == '1' || a[j] = '9'*/)
			//if(ch =='2' || ch =='0')
			{
				sum += i * i;
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}