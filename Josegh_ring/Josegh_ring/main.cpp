#include "list.h"
#include <vector>
#include <iostream>
using namespace std;


int main()
{
	int m = 0,n = 0;
	cout << "请输入初始报数上限值: " << endl;
	cin >> m;
	cout << "请输入人数n: " << endl;
	cin >> n;
	cout << "请依次输入每个人的权重" << endl;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	list::list<pair<int, int>> lst;
	for (int i = 0; i < arr.size(); i++)
	{
		lst.push_back({ i + 1,arr[i] });
	}


	auto cur = lst.begin();
	vector<int> ret;
	while (!lst.empty())
	{
		while (--m)//循环m-1
		{
			++cur;
			if (cur == lst.end()) ++cur;
		}

		auto tmp = cur;
		++cur;
		if (cur == lst.end())
		{
			++cur;
		}
		ret.push_back(tmp->first);//储存编号
		m = tmp->second;//更新m
		lst.erase(tmp);

	}

	//打印结果
	cout << "出列顺序为:" << endl;
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;

	main();
	return 0;
}