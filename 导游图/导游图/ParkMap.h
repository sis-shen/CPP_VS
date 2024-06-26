#pragma once
#include <queue>
#include <iostream>
#include <unordered_set>
#include<vector>
#include<unordered_map>
#include <stdexcept>
#include <functional>
using namespace std;

template <class V = string>
class ParkMap
{
private:
	const int MAX_W = INT_MAX;
	typedef int W;
	bool Direction = false;
public:
	ParkMap(vector<string>& Vertexs, int n, vector<vector<int>>& _Edges)
	{
		_vertexs.reserve(n);
		for (size_t i = 0; i < n; i++)
		{
			_vertexs.push_back(Vertexs[i]);
			_indexMap[Vertexs[i]] = i;
		}

		_matrix.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			_matrix[i].resize(n, MAX_W);
		}

		for (auto arr : _Edges)
		{
			_ADDEdge(arr[0], arr[1], arr[2]);
		}

		FloydWarshall(vvDist, vvPath);
	}

	void short_path_v2v(const string& str1, const string& str2)
	{
		int i, j;
		try//检查是否非法查询
		{
			i = GetVertexIndex(str1);
			j = GetVertexIndex(str2);
		}
		catch (invalid_argument& ia)
		{
			cout << "操作非法:" << ia.what() << endl;
			return;
		}

		if (vvDist[i][j] == INT_MAX)
		{
			cout << "顶点之间无路径" << endl;
			return;
		}
		int ww = vvPath[i][j];

		vector<int>path;
		while (i != j)
		{
			path.push_back(j);
			j = vvPath[i][j];
		}

		path.push_back(i);

		reverse(path.begin(), path.end());

		cout << "最短路径为:(总权值 "<< ww << " ) ";
		for (int i = 0; i < path.size() - 1; i++)
		{
			cout << _vertexs[path[i]] << "->";
		}
		cout << _vertexs [path[path.size() - 1]] << endl;
	}

	void BestPath()
	{
		vector<int> path;
		vector<int> retPath;
		vector<bool> visit(_vertexs.size());
		path.push_back(0);
		int ret = INT_MAX;
		_BestPath(path, 0, 1, 0, visit, ret, retPath);

		cout << "最佳路线为:(总权值 "<<ret<<" ) ";
		for (auto index : retPath)
		{
			cout << _vertexs[index] << "->";
		}
		cout << _vertexs[0]<<endl;
	}

	void _BestPath(vector<int>& path, int srci, int cnt, int pw, vector<bool>& visit, int& ret, vector<int>& retPath)
	{
		if (cnt + 1 == _vertexs.size() && _matrix[srci][0] != INT_MAX)//到达门前且已完成遍历
		{
			if (pw + _matrix[srci][0] < ret)//更短的路径
			{
				retPath = path;
				ret = pw + _matrix[srci][0];
			}
			return;
		}

		for (int j = 0; j < _vertexs.size(); j++)
		{
			if (_matrix[srci][j] != INT_MAX && !visit[j])
			{
				path.push_back(j);
				visit[j] = true;
				_BestPath(path, j, cnt + 1, pw + _matrix[srci][j], visit, ret, retPath);
				visit[j] = false;
				path.pop_back();
			}
		}
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

	void FloydWarshall(vector<vector<W> >& vvDist, vector<vector<int> >& vvpPath)
	{
		size_t n = _vertexs.size();
		vvDist.resize(n);
		vvpPath.resize(n);

		for (size_t i = 0; i < n; i++)
		{
			vvDist[i].resize(n, MAX_W);
			vvpPath[i].resize(n, -1);
		}

		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (_matrix[i][j] != MAX_W)
				{
					vvDist[i][j] = _matrix[i][j];
					vvpPath[i][j] = i;
				}

				if (i == j)
				{
					vvDist[i][j] = 0;
				}
			}
		}
		for (size_t k = 0; k < n; k++)
		{
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					//k作为中间点尝试去更新i->j
					if (vvDist[i][k] != MAX_W and vvDist[k][j] != MAX_W
						and vvDist[i][k] + vvDist[k][j] < vvDist[i][j])
					{
						vvDist[i][j] = vvDist[i][k] + vvDist[k][j];
						vvpPath[i][j] = vvpPath[k][j];
					}
				}
			}
		}
	}
private:
	vector<V> _vertexs;//顶点集合
	vector<vector<int> > _matrix;
	unordered_map<V, int> _indexMap;
	vector<vector<int>> vvDist;
	vector<vector<int>> vvPath;
};