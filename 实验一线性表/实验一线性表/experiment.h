#pragma once

#include <iostream>
#include "slist.h"
#include "list.h"
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;
class Examin
{
public:
	void testMain()
	{
		//测试增删查改
		slist::slist<int> slst;
		slist::slist<int> copy(slst);

		int arr1[] = { 1,2,3,4,5 };
		int arr2[] = { 10,9,8,7,6 };

		cout << "测试尾插" << endl;
		for (auto e : arr1) slst.PushBack(e);
		slst.PrintList();

		cout << "测试头插" << endl;
		for (auto e : arr2) slst.PushFront(e);
		slst.PrintList();

		cout << "测试查找" << endl;
		auto it = slst.Find(8);
		*it = 888;
		slst.PrintList();

		cout << "测试插入" << endl;
		slst.Insert(it,666);
		slst.PrintList();

		cout << "测试删除" << endl;
		slst.Erase(it);
		slst.PrintList();

		cout << "测试尾删*5" << endl;
		int n = 5;
		while (n--) slst.PopBack();
		slst.PrintList();

		cout << "测试头删*4" << endl;
		n = 4;
		while (n--) slst.PopFront();
		slst.PrintList();

	}
};

namespace design
{
	struct city
	{
		typedef pair<int, int> PII;

		string _name;
		PII _pos;

		city(string name="", PII pos = {-1,-1})
			:_name(name)
			,_pos(pos)
		{}

		bool operator==(city c)
		{
			return _name == c._name;
		}

		
	};

	ostream& operator<<(ostream& o, city& c)
	{
		cout << c._name;
		return o;
	}

	class city_list :public slist::slist<city>
	{
	public:
		typedef pair<int, int> PII;
		PII FindPosByName(string name)
		{
			city tmp(name, { 0,0 });//创建临时城市节点，利用重构的==只匹配name相等去Find
			iterator cur = Find(tmp);
			if (cur == end()) return { -1,-1 }; //返回非法坐标，表示没找到

			return cur->_pos;
			
		}

		vector<string> FindCitiesByDistance(PII pos, int distance)
		{
			assert(distance >= 0);
			assert(pos.first >= 0 and pos.second >= 0);
			vector<string> ret;
			iterator cur = begin();
			while (cur != end())
			{
				int x = cur->_pos.first;
				int y = cur->_pos.second;
				int dd = (x - pos.first) * (x - pos.first) + (y - pos.second) * (y - pos.second);
				if (dd <= distance*distance) ret.push_back(cur->_name);

				++cur;
			}

			return ret;
		}
	};

	void ManualTest()
	{
		city_list cl;
		int cnt;
		cout << "请输入城市数量" << endl;
		cin >> cnt;
		while (cnt--)
		{
			cout << "请输入城市名字，横纵坐标,空格隔开" << endl;
			string name;
			int x, y;
			cin >> name >> x >> y;
			city c(name, { x,y });
			cl.PushBack(c);
		}

		cl.PrintList();
	}

	void AutoTest()
	{
		const int N = 100;

		vector<string> city_name({ "ShaoXing","BeiJing","Shanghai","Trump","Biden" });
		srand(time(NULL));

		city_list cl;

		for (int i = 0; i < city_name.size(); i++)
		{
			int x = rand() % N;
			int y = rand() % N;
			cl.PushBack(city(city_name[i], {x,y}));
		}

		//测试查找城市
		cl.PrintList();
		string name;
		cout << "要查找的城市" << endl;
		cin >> name;
		auto pos = cl.FindPosByName(name);
		cout << "城市" << name << "的坐标为" << pos.first << " " << pos.second << endl;

		int pos_x, pos_y;
		int dis = 0;
		cout << "请输入要查找的距离,横纵坐标" << endl;
		cin >> dis>>pos_x>>pos_y;

		auto arr = cl.FindCitiesByDistance({ pos_x,pos_y }, dis);
		
		if (arr.size())
		{
			cout << "找到的城市为:";
			for (auto e : arr)
			{
				cout << e << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "找不到符合条件的城市" << endl;
		}


	}

	void TestMain()
	{
		AutoTest();
	}

}

