#pragma once
#include<vector>
#include<unordered_map>
#include <stdexcept>
using namespace std;


template <class V,class W = int,W MAX_W = INT_MAX,bool Direction = false>
class Gragh
{
public:
	//图的创建
	//1.IO输入
	//2.图结构关系写到文件，读取文件
	//3.手动添加边
	Gragh(const V*a,size_t n)
	{
		_vertexs.reserve(n);
		for (size_t i = 0; i < n; i++)
		{
			_vertexs.push_back(a[i]);
			_indexMap[a[i]] = i;
		}

		_martrix.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			_martrix[i].resize(n, MAX_W);
		}

	}
	void ADDEdge(const V & src, const V & dst, const W & w = 1)
	{
		size_t srci = GetVertexIndex(src);
		size_t dsti = GetVertexIndex(dst);
		_martrix[srci][dsti] = w;
		if (Direction == false)
		{
			_martrix[dsti][srci] = w;
		}

	}

	int GetVertexIndex(const V& v)
	{
		if (_indexMap.count(v))
		{
			return _indexMap[v];
		}
		else
		{
			throw invalid_argument("顶点不存在");
			return -1;
		}
		return 0;
	}
private:
	vector<V> _vertexs;//顶点集合
	vector<vector<W>> _martrix;
	unordered_map<V, int> _indexMap;
};
