#pragma once
#include<vector>
#include<unordered_map>
#include <stdexcept>
#include <functional>
#include "UnionFindSet.h"
#include <queue>
using namespace std;


template <class V,class W = int,W MAX_W = INT_MAX,bool Direction = false>
class Gragh
{
public:
	typedef Gragh<V, W, MAX_W, Direction> Self;
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

		_matrix.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			_matrix[i].resize(n, MAX_W);
		}

	}

	struct Edge
	{
		int _srci;
		int _dsti;
		W _w;

		Edge(size_t srci, size_t dsti, const W& w) :_srci(srci), _dsti(dsti), _w(w) {};

		bool operator>(const Edge& e)
		{
			return _w > e._w;
		}
	};

	W Kruskal(Self& minTree)
	{
		size_t n = _vertexs.size();
		minTree._vertexs = _vertexs;
		minTree._indexMap = _indexMap;
		minTree._matrix.resize(n);
		for (size_t i= 0; i < n; ++i)
		{
			minTree._matrix.resize(n, MAX_W);
		}
		priority_queue<Edge, vector<Edge>, greater<Edge>> minque;
		for(size_t i = 0;i<n;i++)
			for (size_t j = i+1; j < n; j++)
			{
				if ( _matrix[i][j] != MAX_W)
				{
					minque.push(Edge(i, j, _matrix[i][j]));
				}
			}

		int size = 0;
		W totalW = W();
		UnionFindSet ufs(n);
		while (!minque.empty() and size < n-1)
		{
			Edge min = minque.top();
			minque.pop();

			if (!ufs.IsInSet(min._dsti, min._srci))
			{
				minTree._ADDEdge(min._srci, min._dsti, min._w);
				ufs.Union(min._srci, min._dsti);
				++size;
				totalW += min._w;
			}
		}

		if (size == n - 1)
		{
			return totalW;
		}
		else
		{
			return MAX_W;
		}
	}



	void ADDEdge(const V & src, const V & dst, const W & w = 1)
	{
		size_t srci = GetVertexIndex(src);
		size_t dsti = GetVertexIndex(dst);
		_ADDEdge(srci, dsti, w);

	}

	void _ADDEdge(int srci, int dsti, const W& w = 1)
	{
		_matrix[srci][dsti] = w;
		if (Direction == false)
		{
			_matrix[dsti][srci] = w;
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

	//void PrintfMatrix()
	//{
	//	size_t n = _vertexs.size();
	//	for (size_t i = 0; i < n; i++)
	//	{
	//		cout << "[" << i << "]" << _vertexs[i]<<endl;
	//	}

	//	
	//}

	void Dijkstra(const V& src, , vector<W>& dist, vector<int>& pPath)
	{
		size_t srci = GetVertexIndex(src);
		size_t n = _vertexs.size();
		dist.resize(n, MAX_W);
		pPath.resize(n, -1);

		dist[srci] = 0;
		pPath[0] = srci;

		vector<bool> S(n, false);

		int cnt = 1;
		while (cnt < n)
		{
			size_t u = 0;
			W min = MAX_W;
			for (size_t i = 0; i < n; i++)
			{
				if (!S[i] and dist[i] < min)
				{
					u = i;
					min = dist[i];
				}
			}
			S[u] = true;

		}
	}

private:
	vector<V> _vertexs;//顶点集合
	vector<vector<W>> _matrix;
	unordered_map<V, int> _indexMap;
};


namespace link_table
{
	template<class W>
	struct Edge
	{
		int _dsti;//目标点的下标
		//int _srci;
		W _w;
		Edge<W>* _next;

		Edge(int dsti, const W& w) :_dsti(dsti), _w(w) {};
	};


	template <class V, class W , bool Direction = false>
	class Gragh
	{


	public:
		//图的创建
		//1.IO输入
		//2.图结构关系写到文件，读取文件
		//3.手动添加边

		typedef Edge<W> Edge;
		Gragh(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			_tables.resize(n, nullptr);

		}
		void ADDEdge(const V& src, const V& dst, const W& w = 1)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);
			
			Edge* eg = new Edge(dsti, w);
			eg->_next = _tables[srci];
			_tables[srci] = eg;

			if (Direction == false)
			{
				Edge* eg = new Edge(srci, w);
				eg->_next = _tables[dsti];
				_tables[dsti] = eg;
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
		unordered_map<V, int> _indexMap;
		vector<Edge*> _tables;
	};
}