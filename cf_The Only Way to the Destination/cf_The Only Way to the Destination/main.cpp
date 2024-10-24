#include <iostream>
#include <vector>

using namespace std;
int m, n, k;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct Node
{
	Node(int x, int y) :_x(x), _y(y) {}
	int _x;
	int _y;

	void addEdge(Node* node) { _Edges.push_back(node); }

	vector<Node*> _Edges;
};

class Gragh
{
public:
	Gragh(int m, int n)
		:_matrix(m,vector<Node*>(n))
		,_visit(m,vector<bool>(n,false))
		,ret(false)
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				_matrix[i][j] = new Node(i, j);
			}
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (x >= 0 && x < m && y >= 0 && y < n)
					{
						_matrix[i][j]->addEdge(_matrix[x][y]);
					}
				}
			}
		}

	}

	void addWall(int x1, int x2, int y)
	{
		for (int i = x1; i < x2; ++i)
		{
			Node* node = _matrix[i][y];
			auto it = node->_Edges.begin();
			while (it != node->_Edges.end())
			{
				if (*it == _matrix[i + 1][y])
				{
					it = node->_Edges.erase(it);
				}
				else
				{
					++it;
				}
			}
		}

		for (int i = x1+1; i <= x2; ++i)
		{
			Node* node = _matrix[i][y];
			auto it = node->_Edges.begin();
			while (it != node->_Edges.end())
			{
				if (*it == _matrix[i - 1][y])
				{
					it = node->_Edges.erase(it);
				}
				else
				{
					++it;
				}
			}
		}
	}

	bool isRight()
	{
		Node* node = _matrix[0][0];
		_visit[0][0] = true;
		dfs(0, 0, node);
		return ret;
	}

	void dfs(int i, int j,Node* prev)
	{
		if (ret) return;//剪枝
		Node* node = _matrix[i][j];
		int sz = node->_Edges.size();
		for (int k = 0; k < sz; ++k)
		{
			Node* next = node->_Edges[k];
			if (next == prev) continue;//不能回头
			int x = next->_x;
			int y = next->_y;

			if (_visit[x][y])
			{
				//重复访问
				ret = true;
				return;
			}

			_visit[x][y] = true;
			dfs(x, y, node);
			_visit[x][y] = false;
		}
	}

	bool ret;
private:

	vector<vector<Node*>> _matrix;
	vector<vector<bool>> _visit;
};


int main()
{
	cin >> m >> n >> k;
	Gragh g(m, n);
	while (k--)
	{
		int x1, x2, y;
		cin >> x1 >> x2 >> y;

		g.addWall(x1-1, x2-1, y-1);
	}

	bool ret = g.isRight();

	if (ret)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
	
	return 0;
}