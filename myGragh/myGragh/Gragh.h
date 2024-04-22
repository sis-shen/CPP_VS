#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class T,class W = int, W MAX_W = INT_MAX,bool Direction = false>
class Gragh
{
public:
	Gragh(const vector<T>& vertexs)
	{
		int n = vertexs.size()
		for (int i = 0; i < n; i++)
		{
			_vertexs[i] = vertexs[i];
			_indexMap[vertexs[i]] = i;
		}
	}

	void add_edge(const T& src, const T& dst, const W& w = W())
	{

	}

	int find_index(const T& src)
	{
		if (_indexMap.count(src))
		{
			return _indexMap[src];
		}
		else
		{
			cout << "¶¥µã²»´æÔÚ" << endl;
			exit(-1);
		}
	}
private:
	void _add_edge(int srci, int dsti, const W& w = W())
	{

	}

private:
	vector<T> _vertexs;
	unordered_map<T, int> _indexMap;
	vector<vector<W>> _matrix;
};