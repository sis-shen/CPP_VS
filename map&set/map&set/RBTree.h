#pragma once
#pragma once
#include <utility>
using namespace std;
enum Color
{
	RED,
	BLACK,
};

template <class T>
class RBTreeNode
{
public:
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Color _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template <class T,class Ref,class Ptr>
struct __RBTreeIterator
{
	typedef __RBTreeIterator<T, T&, T*> iterator
	typedef __RBTreeIterator<T,Ref,Ptr> self;
	typedef RBTreeNode<T> Node;
	Node* _node;

	__RBTreeIterator(Node* node):_node(node){}

	__RBTreeIterator(const iterator& it) :_node(it._node) {};

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	bool operator!=(const self& s)
	{
		return _node != s._node;
	}

	self& operator++()
	{
		if (_node == nullptr) return *this;
		Node* cur = _node;
		Node* prev = cur;
		cur = cur->_parent;
		if (_node->_left == nullptr)
		{
			while (cur and cur->_parent and cur->_right == prev)
			{
				prev = cur;
				cur = cur->_parent;
			}
		}

		return *this;
	}
};

template <class K, class T,class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;

	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}


public:
	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator begin()
	{
		return iterator(nullptr);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) < key)
				cur = cur->_right;
			else if (kot(cur->_data) > key)
				cur = cur->_left;
			else if (kot(cur->_data) == key)
				return cur;
		}

		return nullptr;
	}

	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}
		KeyOfT kot;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		cur->_col = RED;
		if (kot(parent->_data) > kot(data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}

		cur->_parent = parent;

		//更新颜色
		while (parent and parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle and uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上检查
					cur = grandfather;
					parent = cur->_parent;
				}
				else //u不存在 or u存在且为黑，旋转+变色
				{
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);

						cur->_col = BLACK;
						parent->_col = RED;
						grandfather->_col = RED;
					}
					break;
				}

			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle and uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上检查
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);

						cur->_col = BLACK;
						grandfather->_col = RED;
						parent->_col = RED;
					}
					break;
				}
			}
		}

		_root->_col = BLACK;
		return true;
	}

	//void Inorder()
	//{
	//	_Inorder(_root);
	//	std::cout << std::endl;
	//}

	bool IsBalance()
	{

		return _IsBalance(_root);
	}

	bool Check()
	{
		if (_root and _root->_col == RED)
		{
			cout << "根为红色" << endl;
			return false;
		}

		Node* cur = _root;
		int branchMark = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
				++branchMark;//没统计nullptr
			cur = cur->_left;
		}

		return _Check(_root, 0, branchMark);
	}

	int Height()
	{
		return _Height(_root);
	}
private:
	void _Destroy(Node* root)
	{
		if (root == nullptr) return;

		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;

	}

	bool _Check(Node* root, int blackNum, int branchMark)
	{
		if (root == nullptr)
		{
			if (blackNum != branchMark)
				cout << "blackNum: " << blackNum << endl;
			return true;
		}
		if (root->_col == BLACK) ++blackNum;

		return _CheckColor(root)
			and _Check(root->_left, blackNum, branchMark)
			and _Check(root->_right, blackNum, branchMark);

	}


	void RotateL(Node* parent)
	{
		Node* pparent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		subR->_parent = pparent;
		parent->_parent = subR;

		if (pparent)
		{
			if (pparent->_left == parent)
				pparent->_left = subR;
			else pparent->_right = subR;
		}
		else
		{
			_root = subR;
			_root->_parent = nullptr;
		}

	}

	void RotateR(Node* parent)
	{
		Node* pparent = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR) subLR->_parent = parent;

		subL->_right = parent;
		subL->_parent = pparent;
		parent->_parent = subL;

		if (pparent)
		{
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		}
		else
		{
			_root = subL;
			_root->_parent = nullptr;
		}

	}

	int _Height(Node* root)
	{
		if (root == nullptr) return 0;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);


		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr) return true;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		bool checkCol = _CheckColor(root);

		return std::abs(leftH - rightH) < 2
			and _IsBalance(root->_left)
			and _IsBalance(root->_right);
	}

	bool _CheckColor(Node* root)
	{
		if (root->_parent
			and root->_col == RED
			and root->_parent->_col == RED)
		{
			cout << root->_kv.first << "存在连续红色节点" << endl;
			return false;
		}

		return true;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr) return;

		_Inorder(root->_left);
		std::cout << root->_kv.second << " ";
		_Inorder(root->_right);
	}

private:
	Node* _root = nullptr;
};