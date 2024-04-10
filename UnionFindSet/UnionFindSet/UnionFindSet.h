#pragma once
#include <vector>
#include <map>

using namespace std;

//template <class T>
//class UnionFindSet
//{
//public:
//	UnionFindSet(const T&* a, size_t n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			_a.push_back(a[i]);
//			_indexMap[a[i]] = i;
//		}
//	}
//
//private:
//	vector<T> _a;
//	map<T, int> _indexMap;
//};

class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_ufs(n,-1)
	{}

	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 == root2) return;

		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
	}

	int FindRoot(int x)
	{
		int parent = x;
		while (_ufs[parent] >= 0)
			parent = _ufs[parent];
		return parent;
	}

	bool IsInSet(int x1,int x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}

	size_t SetSize()
	{
		size_t sz = 0;
		for (auto num : _ufs)
			if (num < 0)
				++sz;
		return sz;
	}

private:
	vector<int> _ufs;
};