//#pragma once
//#include<vector>
//#include<unordered_map>
//#include <stdexcept>
//#include <functional>
//#include "UnionFindSet.h"
//#include <queue>
//#include <iostream>
//#include <unordered_set>
//using namespace std;
//
//
//template <class V,class W = int,W MAX_W = INT_MAX,bool Direction = false>
//class Gragh
//{
//public:
//	typedef Gragh<V, W, MAX_W, Direction> Self;
//	//图的创建
//	//1.IO输入
//	//2.图结构关系写到文件，读取文件
//	//3.手动添加边
//	Gragh(const V*a, size_t n)
//	{
//		_vertexs.reserve(n);
//		for (size_t i = 0; i < n; i++)
//		{
//			_vertexs.push_back(a[i]);
//			_indexMap[a[i]] = i;
//		}
//
//		_matrix.resize(n);
//		for (size_t i = 0; i < n; i++)
//		{
//			_matrix[i].resize(n, MAX_W);
//		}
//
//	}
//
//	Gragh(const vector<V>& a, size_t n)
//	{
//		_vertexs.reserve(n);
//		for (size_t i = 0; i < n; i++)
//		{
//			_vertexs.push_back(a[i]);
//			_indexMap[a[i]] = i;
//		}
//
//		_matrix.resize(n);
//		for (size_t i = 0; i < n; i++)
//		{
//			_matrix[i].resize(n, MAX_W);
//		}
//
//	}
//
//	Gragh()
//	{}
//
//
//	struct Edge
//	{
//		size_t _srci;
//		size_t _dsti;
//		W _w;
//
//		Edge(size_t srci = 0, size_t dsti = 0, const W& w = MAX_W) :_srci(srci), _dsti(dsti), _w(w) {}
//
//		Edge(const Edge& e)
//		{
//			_srci = e._srci;
//			_dsti = e._dsti;
//			_w = e._w;
//		}
//
//		bool operator>(const Edge& e) const
//		{
//			return _w > e._w;
//		}
//
//	};
//	
//	W Kruskal(Self& minTree)
//	{
//		size_t n = _vertexs.size();
//		minTree._vertexs = _vertexs;
//		minTree._indexMap = _indexMap;
//		minTree._matrix.resize(n);
//		for (size_t i= 0; i < n; ++i)
//		{
//			minTree._matrix[i].resize(n, MAX_W);
//		}
//		priority_queue<Edge, vector<Edge>, greater<Edge> > minque;
//		for(size_t i = 0;i<n;i++)
//			for (size_t j = i+1; j < n; j++)
//			{
//				if ( _matrix[i][j] != MAX_W)
//				{
//					minque.push(Edge(i, j, _matrix[i][j]));
//				}
//			}
//
//		int size = 0;
//		W totalW = W();
//		UnionFindSet ufs(n);
//		while (!minque.empty() and size < n-1)
//		{
//			Edge min = minque.top();
//			minque.pop();
//
//			if (!ufs.IsInSet(min._dsti, min._srci))
//			{
//				minTree._ADDEdge(min._srci, min._dsti, min._w);
//				ufs.Union(min._srci, min._dsti);
//				++size;
//				totalW += min._w;
//			}
//		}
//
//		if (size == n - 1)
//		{
//			return totalW;
//		}
//		else
//		{
//			return MAX_W;
//		}
//	}
//
//	W prim(Self& minTree,const V& src)
//	{
//		int srci = GetVertexIndex(src);
//		size_t n = _vertexs.size();
//		minTree._vertexs = _vertexs;
//		minTree._indexMap = _indexMap;
//		minTree._matrix.resize(n);
//		for (size_t i = 0; i < n; ++i)
//		{
//			minTree._matrix[i].resize(n, MAX_W);
//		}
//
//		//unordered_set<int> X;
//		//unordered_set<int> Y;
//		//X.insert(srci);
//
//		//for (size_t i = 0; i < n; i++)
//		//{
//		//	if (i != srci)
//		//	{
//		//		Y.insert(i);
//		//	}
//		//}
//
//		priority_queue<Edge, vector<Edge>, greater<Edge> >minq;
//		for (size_t i = 0; i < n; i++)
//		{
//			if (_matrix[srci][i] != MAX_W)
//			{
//				minq.push(Edge(srci, i, _matrix[srci][i]));
//			}
//		}
//		vector<int> X(n, false);
//		vector<int> Y(n, true);
//
//		X[srci] = true;
//		Y[srci] = false;
//
//		size_t cnt = 0;
//		W totalW = W();
//		while (!minq.empty() )
//		{
//			Edge min = minq.top(); minq.pop();
//			
//			//判环
//			if (X[min._srci] and X[min._dsti])
//			{
//				//cout << "构成环：";
//				//cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << " | " <<min._w << endl;
//				continue;
//			}
//
//			minTree._ADDEdge(min._srci, min._dsti, min._w);
//			//打印过程
//			//cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << " | " << min._w << endl;
//
//			X[min._dsti] = true;
//			Y[min._dsti] = false;
//			if (cnt == n - 1) break;
//			totalW += min._w;
//			for (size_t i = 0; i < n; i++)
//			{
//				if (_matrix[min._dsti][i] != MAX_W and Y[i])
//				{
//					minq.push(Edge(min._dsti, i, _matrix[min._dsti][i]));
//				}
//			}
//			cnt++;
//		}
//
//		if (cnt == n - 1)
//		{
//			return totalW;
//		}
//		else
//		{
//			return MAX_W;
//		}
//
//
//	}
//
//	bool BellmanFord(const V& src, vector<W>& dist, vector<int>& pPath)
//	{
//		size_t n = _vertexs.size();
//		size_t srci = GetVertexIndex(src);
//		dist.resize(n, MAX_W);
//		pPath.resize(n, -1);
//
//		dist[srci] = W();
//		for (int k = 0; k < n; k++)//总体最多更新n轮
//		{
//			bool update = false;
//			for (int i = 0; i < n; i++)
//			{
//				for (int j = 0; j < n; j++)
//				{
//					if (_matrix[i][j] != MAX_W and dist[i] != MAX_W and dist[i] + _matrix[i][j] < dist[j])
//					{
//						update = true;
//						dist[j] = dist[i] + _matrix[i][j];
//						pPath[j] = i;
//					}
//				}
//			}
//			if (update == false) break;
//		}
//
//		return true;
//	}
//
//	//===============测试
//	//void Test()
//	//{
//	//	priority_queue<Edge, vector<Edge>, greater<Edge> >minq;
//
//	//}
//
//	void ADDEdge(const V & src, const V & dst, const W & w = 1)
//	{
//		size_t srci = GetVertexIndex(src);
//		size_t dsti = GetVertexIndex(dst);
//		_ADDEdge(srci, dsti, w);
//
//	}
//
//	void _ADDEdge(int srci, int dsti, const W& w = 1)
//	{
//		_matrix[srci][dsti] = w;
//		if (Direction == false)
//		{
//			_matrix[dsti][srci] = w;
//		}
//	}
//
//
//	int GetVertexIndex(const V& v)
//	{
//		if (_indexMap.count(v))
//		{
//			return _indexMap[v];
//		}
//		else
//		{
//			throw invalid_argument("顶点不存在");
//			return -1;
//		}
//		return 0;
//	}
//
//	//void PrintfMatrix()
//	//{
//	//	size_t n = _vertexs.size();
//	//	for (size_t i = 0; i < n; i++)
//	//	{
//	//		cout << "[" << i << "]" << _vertexs[i]<<endl;
//	//	}
//
//	//	
//	//}
//
//	void PrintShortPath(const V& src, vector<W>& dist, vector<int>& pPath)
//	{
//		size_t srci = GetVertexIndex(src);
//		size_t n = _vertexs.size();
//		for (size_t i = 0; i < n; ++i)
//		{
//			if (i != srci)
//			{
//				vector<int> path;
//				size_t parenti = i;
//				while (parenti != srci)
//				{
//					path.push_back(parenti);
//					parenti = pPath[parenti];
//				}
//				path.push_back(srci);
//				reverse(path.begin(), path.end());
//
//				for (auto index : path)
//				{
//					cout << _vertexs[index] << "->";
//				}
//				cout<<"|" << dist[i] << endl;
//			}
//		}
//	}
//
//	void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
//	{
//		int srci = GetVertexIndex(src);
//		int n = _vertexs.size();
//		dist.resize(n, MAX_W);
//		pPath.resize(n, -1);
//
//		dist[srci] = 0;
//		pPath[0] = srci;
//
//		vector<bool> S(n, false);
//
//		int cnt = 1;
//		while (cnt < n)
//		{
//			int u = 0;
//			W min = MAX_W;
//			for (size_t i = 0; i < n; i++)
//			{
//				if (!S[i] and dist[i] < min)
//				{
//					u = i;
//					min = dist[i];
//				}
//			}
//			S[u] = true;
//
//			//松弛更新
//			for (int v = 0; v < n; v++)
//			{
//				if (S[u] == false and _matrix[u][v] != MAX_W and dist[u] + _matrix[u][v] < dist[v])
//				{
//					dist[v] = dist[u] + _matrix[u][v];
//					pPath[v] = u;	
//				}
//			}
//			cnt++;
//		}
//	}
//
//	void Print()
//	{
//		for (auto e : _vertexs)
//		{
//			cout << e << " ";
//		}
//		cout<<endl<<endl;
//
//		for (int i = 0; i < _vertexs.size(); i++)
//		{
//			for (int j = 0; j < _vertexs.size(); j++)
//			{
//				if (i < j and _matrix[i][j] != MAX_W)
//				{
//					cout << _vertexs[i] << "->" << _vertexs[j] <<" | "<<_matrix[i][j]<< endl;
//				}
//				if (Direction and i > j and _matrix[i][j] != MAX_W)
//				{
//					cout << _vertexs[i] << "->" << _vertexs[j] <<" | " << _matrix[i][j]<< endl;
//				}
//			}
//		}
//
//	}
//
//	void FloydWarshall(vector<vector<W> >& vvDist, vector<vector<int> >& vvpPath)
//	{
//		size_t n = _vertexs.size();
//		vvDist.resize(n);
//		vvpPath.resize(n);
//
//		for (size_t i = 0; i < n; i++)
//		{
//			vvDist[i].resize(n, MAX_W);
//			vvpPath[i].resize(n, -1);
//		}
//
//		for (size_t i = 0; i < n; ++i)
//		{
//			for (size_t j = 0; j < n; j++)
//			{
//				if (_matrix[i][j] != MAX_W)
//				{
//					vvDist[i][j] = _matrix[i][j];
//					vvpPath[i][j] = i;
//				}
//
//				if (i == j)
//				{
//					vvDist[i][j] = 0;
//				}
//			}
//		}
//		for (size_t k = 0; k < n; k++)
//		{
//			for (size_t i = 0; i < n; ++i)
//			{
//				for (size_t j = 0; j < n; ++j)
//				{
//					//k作为中间点尝试去更新i->j
//					if (vvDist[i][k] != MAX_W and vvDist[k][j] != MAX_W
//						and vvDist[i][k] + vvDist[k][j] < vvDist[i][j])
//					{
//						vvDist[i][j] = vvDist[i][k] + vvDist[k][j];
//						vvpPath[i][j] =vvpPath[k][j];
//					}
//				}
//			}
//		}
//	}
//
//protected:
//	vector<V> _vertexs;//顶点集合
//	vector<vector<W> > _matrix;
//	unordered_map<V, int> _indexMap;
//};
//
//
//namespace link_table
//{
//	template<class W>
//	struct Edge
//	{
//		int _dsti;//目标点的下标
//		//int _srci;
//		W _w;
//		Edge<W>* _next;
//
//		Edge(int dsti, const W& w) :_dsti(dsti), _w(w) {};
//	};
//
//
//	template <class V, class W , bool Direction = false>
//	class Gragh
//	{
//
//
//	public:
//		//图的创建
//		//1.IO输入
//		//2.图结构关系写到文件，读取文件
//		//3.手动添加边
//
//		typedef Edge<W> Edge;
//		Gragh(const V* a, size_t n)
//		{
//			_vertexs.reserve(n);
//			for (size_t i = 0; i < n; i++)
//			{
//				_vertexs.push_back(a[i]);
//				_indexMap[a[i]] = i;
//			}
//
//			_tables.resize(n, nullptr);
//
//		}
//		void ADDEdge(const V& src, const V& dst, const W& w = 1)
//		{
//			size_t srci = GetVertexIndex(src);
//			size_t dsti = GetVertexIndex(dst);
//			
//			Edge* eg = new Edge(dsti, w);
//			eg->_next = _tables[srci];
//			_tables[srci] = eg;
//
//			if (Direction == false)
//			{
//				Edge* eg = new Edge(srci, w);
//				eg->_next = _tables[dsti];
//				_tables[dsti] = eg;
//			}
//
//		}
//
//		int GetVertexIndex(const V& v)
//		{
//			if (_indexMap.count(v))
//			{
//				return _indexMap[v];
//			}
//			else
//			{
//				throw invalid_argument("顶点不存在");
//				return -1;
//			}
//			return 0;
//		}
//	private:
//		vector<V> _vertexs;//顶点集合
//		unordered_map<V, int> _indexMap;
//		vector<Edge*> _tables;
//	};
//}