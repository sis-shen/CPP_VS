#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>    
#include <iomanip> 
#include <iostream>

using namespace std;

// 糖果类
class Candy
{
	friend class CandyMachine;
public:
	Candy(const string& name, double price, int count)
		:_name(name)
		,_price(price)
		,_count(count)
	{}

private:
	string _name;
	double _price;
	int _count;
};


class CandyMachine
{
public:
	CandyMachine(int capacity = 100)
		:_amount(0)
		,_sale(0)
		,_capacity(capacity)
	{}

	bool AddCandy(); // 增加糖果
	bool SellCandy(); // 售卖糖果

	void InfoCandy(); // 显示某一种糖果的信息
	void InfoCandies(); // 显示所有糖果的信息，按价格排序

	void Run(); // 开始售卖

private:
	// 添加糖果到售卖机  
	bool _AddCandy(const string& name, double price, int num);

	// 售卖指定数量的糖果  
	bool _SellCandy(const string& name, int num);

	// 显示特定糖果的信息  
	void _InfoCandy(const string& name);

	// 显示所有糖果的信息  
	void _InfoCandies(const vector<Candy>& goodslist);

	// 打印操作菜单  
	void PrintMenu();

	vector<Candy> _CandiesList; // 存储糖果列表  
	unordered_map<string, int> _index; // 存储糖果名称到索引的映射  

	double _amount; // 糖果的总价值  
	double _sale;   // 总销售额  
	int _capacity;  // 最大容量，指售卖机能存放的糖果总价值  
};
