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
				_index[arr[i]] = i;
				Node* cur = new Node(weighs[i]);
				_IndexToNode[i] = cur;
				_Node2Index[cur] = i;
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
				_Node2Index[cur] = i;
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
					parent->_right = cur1;
				}

				minq.push(parent);
			}
		}

		void print_tree()
		{
			int height = tree_height();

			int sz = pow(2, height);
			vector<Node*> tree(sz, nullptr);
			fill_full_tree(minq.top(), tree, 0);//从根开始构建满二叉树
			
			for (int i = 0; i < sz; i++)
			{
				int h = sqrt(i+1);
				//打印空格
				Node* root = tree[i];
				string line;
				for (int j = 0; j < pow(2, height - h) - 1; j++)
					line.push_back(' ');
				cout << line;
			}

		}
	private:
		void fill_full_tree(Node* root, vector<Node*>& arr,int pos)
		{
			arr[pos] = root;
			if (root->_left)
				fill_full_tree(root->_left, arr, pos * 2 + 1);
			if (root->_right)
				fill_full_tree(root->_right, arr, pos * 2 + 2);
		}

		int tree_height()
		{
			Node* root = minq.top();
			return _tree_height(root);
		}

		int _tree_height(Node* root)
		{
			if (root == nullptr) return 0;
			int left = tree_height(root->_left);
			int right = tree_height(root->_right);
			return 1 + max(left, right);
		}

	public:

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
				cout << "failed to get " << t << endl;
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
			for (int i = 0; i < _vertexs.size(); i++)//重建哈希表
			{
				_index[_vertexs[i]] = i;
			}
			remake_tree();
		}

		string decode(const string& code)
		{
			string ret;
			int index = 0;
			Node* root = minq.top();
			Node* cur = root;
			while (index < code.size())
			{
				if (cur->_left == nullptr && cur->_right == nullptr)
				{
					//找到叶子节点，即到头了
					T ch = _vertexs[_Node2Index[cur]];//尾插字节
					if (ch == '#')
						ret.push_back(' ');
					else
						ret.push_back(ch);
					cur = root;//重新找下一个字节
				}
				if (code[index] == '0')
				{
					if (cur->_left == nullptr) assert(false);
					cur = cur->_left;
				}
				else
				{
					if (cur->_right == nullptr) assert(false);
					cur = cur->_right;
				}
				index++;
			}

			T ch = _vertexs[_Node2Index[cur]];//尾插字节
			if (ch == '#')
				ret.push_back(' ');
			else
				ret.push_back(ch);

			//reverse(ret.begin(), ret.end());
			return ret;
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
		vector<T> _vertexs;//下标->顶点
		vector<int> _weigh;//下标->权重
		unordered_map<T, int> _index;//顶点->下标
		unordered_map<int, Node*> _IndexToNode;//下标->节点
		unordered_map<Node*, int> _Node2Index;//节点->下标
		priority_queue<Node*, vector<Node*>, Cmp> minq;
	};
}
