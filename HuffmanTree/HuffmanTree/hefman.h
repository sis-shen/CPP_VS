#pragma once
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cassert>
#include <fstream>
using namespace std;


namespace sup
{
	struct Node
	{
		int _w;
		Node* _left;
		Node* _right;
		Node* _parent;

		Node(int w):_w(w),_left(nullptr),_right(nullptr),_parent(nullptr)
		{}
	};

	struct Cmp
	{
		bool operator()(Node* left, Node* right)
		{
			return left->_w > right->_w;
		}
	};

	template<class T = char>
	class HefmanTree
	{
	public:

		HefmanTree(const vector<T>& arr = vector<T>(), const vector<int>& weighs = vector<int>())
		{
			int n = arr.size();
			_vertexs.resize(n);
			_weigh.resize(n);
			for (int i = 0; i < n; i++)
			{
				_vertexs[i] = arr[i];
				_weigh[i] = weighs[i];
				_index[weighs[i]] = i;
				Node* cur = new Node(weighs[i]);
				_IndexToNode[i] = cur;
				minq.push(cur);
			}
			//checkQ();
			make_tree();
		}

		HefmanTree(const HefmanTree<T>& ht)
		{
			_vertexs = ht._vertexs;
			_weigh = ht._weigh;
			remake_tree();
		}

		void remake_tree()//已建树时使用
		{
			destroy_tree();//先销毁已有的树和优先级队列

			int n = _vertexs.size();
			for (int i = 0; i < n; i++)
			{
				Node* cur = new Node(_weigh[i]);
				_IndexToNode[i] = cur;
				minq.push(cur);
			}

			make_tree();
		}

		void add_vertex(const T& t, int w)
		{
			if (_index.count(t))
			{
				update_vertex(t, w);
			}

			_index[t] = _vertexs.size();
			_vertexs.push_back(t);
			_weigh.push_back(w);
			remake_tree();
		}

		void update_vertex(const T& t, int w)
		{
			if (!_index.count(t))
			{
				add_vertex(t, w);
			}

			int i = _index[t];

			_weigh[i] = w;

			make_tree();
		}

		void checkQ()
		{
			priority_queue<Node*, vector<Node*>, Cmp> copy = minq;
			cout << "CheckQ" << endl;
			while (copy.size())
			{
				Node* cur = copy.top();
				copy.pop();
				cout << cur->_w << " ";
			}
			cout << endl;
		}

		void make_tree()//顶点和权重已就绪,第一层节点已就绪，从零建树
		{
			while (minq.size() > 1)
			{
				Node* cur1 = minq.top(); minq.pop();
				Node* cur2 = minq.top(); minq.pop();
				Node* parent = new Node(cur1->_w + cur2->_w);
				cur1->_parent = parent;
				cur2->_parent = parent;

				if (cur1->_w < cur2->_w)
				{
					parent->_left = cur1;
					parent->_right = cur2;
				}
				else
				{
					parent->_left = cur2;
					parent->_right = cur2;
				}

				minq.push(parent);
			}
		}

		void print_tree()
		{
			queue<Node*> q;
			q.push(minq.top());
			while (q.size())
			{
				int n = q.size();
				while (n--)
				{
					Node* cur = q.front(); q.pop();
					cout << cur->_w << "  ";

					if (cur->_left) q.push(cur->_left);
					if (cur->_right) q.push(cur->_right);
				}
				cout << endl;
			}
		}

		string generate_code(const T& t)
		{
			int index = get_index(t);
			return _generate_code(index);
		}

		void print_code_list()
		{
			for (int i = 0; i < _vertexs.size(); i++)
			{
				cout << _vertexs[i] << ":" << _weigh[i] << " code:" << _generate_code(i)<<endl;
			}
		}

		int get_index(const T& t)
		{
			if (_index.count(t))
			{
				return _index[t];
			}
			else
			{
				assert(false);
			}
		}

		void whrite_file(const string& filename)
		{
			fstream f;
			f.open("hfmTree.txt", ios::out);
			for (auto e : _vertexs)
			{
				f << e << " ";
			}
			f << endl;

			for (auto i : _weigh)
			{
				f << i << " ";
			}

			f.close();
		}

		void read_file(const string& filename)
		{
			_weigh.resize(0);
			_vertexs.resize(0);
			fstream f;
			f.open("hfmTree.txt", ios::in);

			string line;
			getline(f, line);
			for (auto ch : line)
			{
				if (ch != ' ')
				{
					_vertexs.push_back(ch);
				}
			}

			getline(f, line);
			int num = 0;
			for (auto ch : line)
			{
				if (ch == ' ')
				{
					_weigh.push_back(num);
					num = 0;
				}
				else
				{
					num = num * 10 - '0' + ch;
				}
			}
			f.close();
			for (int i = 0; i < _vertexs.size(); i++)
			{
				_index[_vertexs[i]] = i;
			}
			remake_tree();
		}

		bool empty()
		{
			return _vertexs.size() == 0;
		}

	private:
		string _generate_code(int index)
		{
			Node* cur = _IndexToNode[index];
			string ret;
			while (cur->_parent)
			{
				Node* parent = cur->_parent;
				if (cur == parent->_left) ret.push_back('0');
				else ret.push_back('1');

				cur = parent;
			}
			reverse(ret.begin(), ret.end());
			return ret;
		}

		void destroy_tree()
		{
			while (minq.size())
			{
				Node* cur = minq.top();
				minq.pop();
				_destroy_tree(cur);
			}
		}

		void _destroy_tree(Node* root)
		{
			if (root == nullptr) return;

			_destroy_tree(root->_left);
			_destroy_tree(root->_right);

			delete root;
		}

	private:
		vector<T> _vertexs;
		vector<int> _weigh;
		unordered_map<T, int> _index;
		unordered_map<int, Node*> _IndexToNode;
		priority_queue<Node*, vector<Node*>, Cmp> minq;
	};
}
