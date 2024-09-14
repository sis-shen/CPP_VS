#pragma once
#include <functional>
#include <cassert>
#include <iostream>

typedef bool Color;//只有红黑两种颜色，正好使用bool类型
const Color Red = false;//定义两种颜色
const Color Black = true;

//红黑树结点的定义
template <class ValueType>
struct RBTreeNode
{
	typedef RBTreeNode<ValueType> Node;//简化代码
	Node* _left;
	Node* _right;
	Node* _parent;
	Color _color;

	ValueType _value;
	RBTreeNode(const ValueType& val, Color color)
		:_value(val)
		, _color(color)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}
};

template <class Value,class Ref,class Ptr>
class __rbtree_iterator
{
	typedef __rbtree_iterator<Value, const Value&, const Value*> const_iterator;
	typedef __rbtree_iterator<Value, Ref, Ptr> self;
	typedef RBTreeNode<Value>* linkeType;

public:
	__rbtree_iterator(const linkeType& ptr)
		:_ptr(ptr)
	{}

	__rbtree_iterator(const const_iterator& const_it)
		:_ptr(const_it._ptr)
	{}

	self operator++()
	{
		if (_ptr == nullptr || _ptr->_right == _ptr )
		{
			exit(-1);//end()迭代器不能++,空迭代器不能加减
		}
		if (_ptr->_right)
		{
			_ptr = _ptr->_right;
		}
		else
		{
			linkeType parent = _ptr->_parent;
			while (parent->_right == _ptr)
			{
				_ptr = parent;
				parent = _ptr->_parent;
			}
			if (parent->_right == nullptr || parent->_right==parent)
			{
				//特殊情况，子树的根节点没有右子树
				_ptr = parent;
			}
		}
		return (*this);
	}

	self operator--()
	{
		if (_ptr == nullptr)
		{
			exit(-1);//非法情况
		}
		else if (_ptr->_left == _ptr)//在头结点
		{
			linkeType right = _ptr->_parent;//走到根节点
			while (right)
			{
				_ptr = right;
				right->_ptr;
			}
		}
		else if (_ptr->_left)
		{
			_ptr = _ptr->_left;
			linkeType right = _ptr->_right;
			while (right)
			{
				_ptr = right;
				right = _ptr->_right;
			}
		}
		else
		{
			linkeType parent = _ptr->_parent;
			while (parent->_left == _ptr)
			{
				_ptr = parent;
				parent = _ptr->_parent;
			}
			_ptr = parent;
		}

		return *this;
	}

	Ref operator*()
	{
		return *_ptr;
	}

	Ptr operator->()
	{
		return _ptr;
	}


private:
	linkeType _ptr;
};

template<class K,class V,class KeyOfValue,class Compare = std::greater<int>>
class RBTree
{
	typedef RBTreeNode<V> Node;
	typedef RBTree<K, V, KeyOfValue, Compare> self;
	typedef __rbtree_iterator<V, V&, V*> iterator;
	typedef __rbtree_iterator<V, const V&, const V*>const_iterator;

public:
	RBTree(const Compare& cmp =Compare())
		:_cmp(cmp), _header(nullptr)
	{
		//创建哨兵位头结点，使后面调整树形状不用区分根节点
		_header = new Node(V(), Black);
		_header->_left = _header;
		_header->_right = _header;
	}

	RBTree(const self& rbt)
	{
		for (auto value : rbt)
		{
			Insert(value);
		}
	}

public:
	iterator begin()
	{
		return iterator(Most_Left());
	}

	iterator end()
	{
		return iterator(_header);
	}

	const_iterator begin()const
	{
		return const_iterator(Most_Left());
	}

	const_iterator end()const
	{
		return const_iterator(_header);
	}

public:
	void Inorder()
	{
		_Inorder(GetRoot());
		std::cout << "nullptr" << std::endl;
	}

protected:
	void _Inorder(Node* root)
	{
		if (root == nullptr) return;
		_Inorder(root->_left);
		std::cout << root->_value << "->";
		_Inorder(root->_right);
	}
public:
	int Height()
	{
		return _Height(GetRoot());
	}
private:
	int _Height(Node* root)
	{
		if (root == nullptr) return 0;

		int LHeight = _Height(root->_left);
		int RHeight = _Height(root->_right);
		if (LHeight > RHeight) return LHeight + 1;
		else return RHeight + 1; //将左右子树相等的情况合并在这里
	}

public:
	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		if (root->_color != Black)return false;//违反根节点染色规则
		
		int blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->_color == Black) blackCount++;
			cur = cur->_left;
		}

		blackCount++;//cur为nullptr时也算作一个黑节点

		return _IsValidRBTree(root,0,blackCount);
	}

protected:
	bool _IsValidRBTree(Node* root,int cnt,const int blackCount)
	{
		if (root == nullptr)
		{
			cnt++;
			if (cnt == blackCount)return true;
			else return false;//黑色节点数量不相等
		}
		//检测与父结点的染色规则
		if (root->_color == Red && root->_parent->_color == Red)
		{
			return false;
			//不能有连续的红色节点
		}

		if (root->_color == Black) cnt++;
		return _IsValidRBTree(root->_left, cnt, blackCount)
			&& _IsValidRBTree(root->_right, cnt, blackCount);
	}

public:
	bool Find(const K& key)
	{
		Node* prev = nullptr;
		Node* cur = GetRoot();
		while (cur)
		{
			if (_cmp(_kof(cur->_value), key))//相等或在左子树
			{
				prev = cur;
				cur = left(cur);
			}
			else
			{
				cur = right(cur);//可能在右子树
			}
		}

		if (prev == nullptr || _cmp(_kof(prev->_value),key))//一直向右走或一直向左走
		{
			return false;
		}
		else return true;//走到头的过程中左转了一次之后一直向右走
	}

	bool Insert(const V& value)
	{
		Node* proot = GetRoot();
		if (proot == nullptr)//树为空
		{
			Node* newnode = new Node(value, Black);
			newnode->_parent = _header;
			_header->_parent = newnode;
			return true;
		}

		if (Find(_kof(value)))return false;//结点已存在，插入失败
		Node* cur = proot;
		Node* parent = proot->_parent;
		while (cur)
		{
			if (_cmp(_kof(cur->_value), _kof(value)))
			{
				//插在左子树
				parent = cur;
				cur = left(cur);
			}
			else
			{
				//插在右子树
				parent = cur;
				cur = right(cur);
			}
		}
		//开始插入
		Node* newnode = new Node(value, Red);
		if (_cmp(_kof(parent->_value),_kof(value) ))
		{
			//插入右子树
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}

		cur = newnode;
		//开始调整
		while (parent != _header && parent->_color == Red)
		{
			Node* gp = parent->_parent;
			Node* uncle = nullptr;
			if (parent == gp->_left)uncle = gp->_right;
			else uncle = gp->_left;

			if (uncle && uncle->_color == Red)//情况一
			{
				parent->_color = Black;
				uncle->_color = Black;
				gp->_color = Red;

				cur = gp;
				parent = gp->_parent;
			}
			else if (cur == parent->_left && parent == gp->_left)
			{
				RotateR(cur);
				break;
			}
			else if (cur == parent->_right && parent == gp->_right)
			{
				RotateL(cur);
				break;
			}
			else if (cur == parent->_right && parent == gp->_left)
			{
				RotateLR(cur);
				break;
			}
			else if (cur == parent->_left && parent == gp->_right)
			{
				RotateRL(cur);
				break;
			}
		}

		Node* root = GetRoot();
		root->_color = Black;//修改根节点颜色
		_header->_left = _header;
		_header->_right = _header;
		return true;
	}

private:
	void RotateR(Node* node)
	{
		if (node == nullptr)assert(false);
		Node* cur = node;
		Node* parent = cur->_parent;
		if (parent == nullptr) assert(false);
		Node* gp = parent->_parent;
		if (gp == nullptr) assert(false);

		//调整树结构
		Node* ggp = gp->_parent;
		if (gp == ggp->_left)ggp->_left = parent;
		else ggp->_right = parent;
		parent->_parent = ggp;

		gp->_left = parent->_right;
		parent->_right = gp;
		gp->_parent = parent;

		if (gp == GetRoot())
		{
			SetRoot(parent);
		}

		//染色
		parent->_color = Black;
		gp->_color = Red;
	}

	void RotateL(Node* node)
	{
		Node* cur = node;
		if (cur == nullptr)assert(false);
		Node* parent = cur->_parent;
		if (parent == nullptr)assert(false);
		Node* gp = parent->_parent;
		if (gp == nullptr)assert(false);

		//调整树结构
		Node* ggp = gp->_parent;
		if (ggp->_left == gp) ggp->_left = parent;
		else ggp->_right = parent;
		parent->_parent = ggp;
		
		gp->_right = parent->_left;
		parent->_left = gp;
		gp->_parent = parent;

		if (gp == GetRoot())
		{
			SetRoot(parent);
		}

		//染色
		parent->_color = Black;
		gp->_color = Red;
	}

	void RotateLR(Node* node)
	{
		Node* cur = node;
		if (cur == nullptr)assert(false);
		Node* parent = cur->_parent;
		if (parent == nullptr)assert(false);
		Node* gp = parent->_parent;
		if (gp == nullptr) assert(false);

		parent->_right = cur->_left;
		cur->_left = parent;
		parent->_parent = cur;
		cur->_parent = gp;
		gp->_left = cur;

		RotateR(parent);
	}

	void RotateRL(Node* node)
	{
		Node* cur = node;
		if (cur == nullptr)assert(false);
		Node* parent = cur->_parent;
		if (parent == nullptr)assert(false);
		Node* gp = parent->_parent;
		if (gp == nullptr) assert(false);

		parent->_left = cur->_right;
		cur->_right = parent;
		parent->_parent = cur;
		cur->_parent = gp;
		gp->_right = cur;

		RotateL(parent);
	}

private:
	Node* GetRoot()
	{
		if (_header->_parent == _header)return nullptr;
		else return _header->_parent;
	}

	Node* SetRoot(Node* root)
	{
		if (root == nullptr)return nullptr;
		root->_parent = _header;
		_header->_parent = root;
		return root;
	}

	Node* left(Node* root)
	{
		if (root == nullptr)return nullptr;
		return root->_left;
	}

	Node* right(Node* root)
	{
		if (root == nullptr)return nullptr;
		return root->_right;
	}

	Node* Most_Left()
	{
		Node* cur = GetRoot();
		Node* prev = _header;
		while (cur)
		{
			prev = cur;
			cur = left(cur);
		}
		return prev;
	}

	Node* Most_Right()
	{
		Node* cur = GetRoot();
		Node* prev = _header;
		while (cur)
		{
			prev = cur;
			cur = right(cur);
		}
		return prev;
	}

private:
	Compare _cmp;
	KeyOfValue _kof;
	Node* _header;
};