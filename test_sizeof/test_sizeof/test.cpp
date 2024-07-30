////
////
//////int g_arr[10] = { 0 };
//////
//////void func(int st_arr[])
//////{
//////	cout << sizeof(st_arr) << endl;//此处退化为指针变量，输出4或8
//////}
//////
//////int main()
//////{
//////	int arr[10] = { 0 };
//////	cout << sizeof(g_arr) << endl;//输出40
//////	cout << sizeof(arr) << endl; //输出40
//////	func(arr);//输出4/8
//////	return 0;
//////}
////
//////class R
//////{
//////	int _a, _b, _c;
//////};
//////
//////class A
//////{
//////	char _ch;
//////	short _s;
//////};
//////
//////int main()
//////{
//////	cout << sizeof(A);
//////	return 0;
//////}
////
////
////#define  _CRT_SECURE_NO_WARNINGS 1
////#include <stdio.h>
////
////int main()
////{
////	FILE* pFile;
////	pFile = fopen("example.txt", "wb");
////	fputs("This is an apple.", pFile);
////	fseek(pFile, -5, SEEK_CUR);
////	fputs(" sam", pFile);
////	fclose(pFile);
////	return 0;
////}
//
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//int n;
//string s("shy");
//unordered_map<char, vector<int> > index;
//int ret = 0;
//void dfs(int cur, int last_pos)
//{
//    cout << "1";
//    char ch = s[cur];
//    int left = 0, right = index[ch].size() - 1;
//    while (left < right)
//    {
//        int mid = (left + right) / 2;
//        if (index[ch][mid] <= last_pos) left = mid + 1;
//        else right = mid;
//    }
//    cout << "1";
//    for (int i = right; right < index[ch].size(); ++i)
//    {
//        if (cur == 1)
//        {
//            dfs(2, index[ch][i]);
//        }
//        else
//        {
//            ret++;
//        }
//    }
//}
//
//int main() {
//
//    string str;
//    cin >> n >> str;
//    for (int i = 0; i < n; ++i)
//    {
//        char e = str[i];
//        if (e == 's' || e == 'h' || e == 'y')
//            index[e].push_back(i);
//    }
//    for (auto e : index['s'])
//    {
//        dfs(1, e);
//    }
//
//    cout << ret;
//
//}


#include <iostream>
#include "vector"
#include "cmath"
using namespace std;
vector<int> arr(1, 0);


int main() {
	

}