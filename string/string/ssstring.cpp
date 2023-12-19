#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//int main()
//{
//	string s1("hello world");
//	s1 += "what";
//	cout << s1 << endl;
//
//	string::iterator it = s1.begin();
//
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//		
//	}
//	cout << "===" << endl;
//
//	for (auto ch : s1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


int main()
{
	string s1("hello world");
	string::reverse_iterator it = s1.rbegin();//·´Ïòµü´úÆ÷
	
	s1.reserve(100);
	cout << s1 << " " << s1.size();

	return 0;
}