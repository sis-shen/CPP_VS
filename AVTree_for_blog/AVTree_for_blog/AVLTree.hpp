#pragma once

#include <utility>
#include <iostream>
#include <cassert>

template <class K,class V>
struct AVLTreeNode
{
	typedef AVLTreeNode<K, V> Node;//使用typedef简化代码
	Node* _left;                   
	Node* _right;
	Node* _parent;
	std::pair<K, V> _kv; //节点储存的键值对
	int _bf;// ballance factor 平衡因子

	//构造函数，但不提供无参的默认构造函数
	AVLTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K, class V,class Cmp = std::greater<K>>//使用仿函数
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
	typedef std::pair<K, V> PKV;
public:
	AVLTree() :_root(nullptr) {}//默认构造函数

	void Inorder()
	{
		_Inorder(_root);
		std::cout<<"nullptr" << std::endl;
	}

protected:
	void _Inorder(Node* root)
	{
		if (root == nullptr) return;
		_Inorder(root->_left);
		std::cout << root->_kv.second << "->";
		_Inorder(root->_right);
	}
public:
	int Height()
	{
		return _Height(_root);
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
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
private:
	bool _IsBalance(Node* root)
	{
		if (root == nullptr) return true;
		bool left = _IsBalance(root->_left);
		bool right = _IsBalance(root->_right);

		if (left == false || right == false) return false;//先判定左右子树

		int LHeight = _Height(root->_left);
		int RHeight = _Height(root->_right);

		if (LHeight - RHeight >= 2 || LHeight - RHeight <= -2)return false;//最后判定根
		else return true;
	}

public:
	bool Insert(const PKV& kv)
	{
		Cmp cmp;//仿函数实例化一个对象
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		//寻找插入位置
		while (cur)
		{
			if (cur->_kv.first == kv.first)
			{
				//该键下的节点已存在，发生冲突
				return false;
			}
			else if (cmp(cur->_kv.first, kv.first))//根比节点"大"
			{
				parent = cur;
				cur = cur->_left;
			}
			else //根比节点小
			{
				parent = cur;
				cur = cur->_right;
			}
		}

		//开始插入
		Node* node = new Node(kv);
		if (cmp(parent->_kv.first, kv.first))//应该插入左边
		{
			parent->_left = node;
			node->_parent = parent;
			parent->_bf -= 1;//_bf越小，左子树越高
		}
		else //插入右子树
		{
			parent->_right = node;
			node->_parent = parent;
			parent->_bf += 1;//_bf越大，右子树越高
		}
		//插入完成，准备开始维护平衡
		while (true)
		{
			if (parent->_bf == 0)break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//子树高度增加
				node = parent;
				parent = parent->_parent;
				if (parent == nullptr)break;//走到根节点了
				if (node == parent->_left)
				{
					parent->_bf -= 1;
				}
				else if (node == parent->_right)
				{
					parent->_bf += 1;
				}
				else
				{
					assert(false);//非法情况
				}
			}
			else if (parent->_bf == -2)
			{
				if (parent->_left->_bf == 0)
				{
					assert(false);//非法情况,不可能左右子树同时超高
				}
				else if (parent->_left->_bf == -1)
				{
					//子树的左子树超高
					RotateR(parent);
					break;
				}
				else if (parent->_left->_bf == 1)
				{
					//子树的右子树超高
					RotateLR(parent);
				}
			}
			else if (parent->_bf == 2)
			{
				if (parent->_right->_bf == 0)
				{
					assert(false);//非法情况,不可能左右子树同时超高
				}
				else if (parent->_right->_bf == 1)
				{
					//子树的右子树超高
					RotateL(parent);
					break;
				}
				else if (parent->_right->_bf == -1)
				{
					//子树的左子树超高
					RotateRL(parent);
					break;
				}
			}
			else
			{
				assert(false);//非法情况
			}
		}
		return true;
	}

private:
	void RotateR(Node* parent)
	{
		if (parent == nullptr) return;
		Node* child = parent->_left;

		//维护树的结构
		parent->_left = child->_right;//过继子树的右子树
		child->_right = parent;//重构树结构
		Node* grandParent = parent->_parent;//维护祖父节点
		child->_parent = grandParent;//维护child
		parent->_parent = child;
		if (grandParent)//如果不是根节点
		{
			//维护根节点的父节点的子树
			if (parent == grandParent->_left) grandParent->_left = child;
			else grandParent->_right = child;
		}
		
		//维护平衡因子
		if (child->_bf == -1)
		{
			child->_bf = 0;
			parent->_bf = 0;
		}
		else if (child->_bf == 0)
		{
			assert(false);//不存在的情况
		}
		else
		{
			assert(false);//需要多次旋转时不应该调用该函数
		}

		if (parent == _root)
		{
			_root = child;//更新根节点
		}
	}

private:
	void RotateL(Node* parent)
	{
		if (parent == nullptr) return;
		Node* child = parent->_right;
		//维护树结构
		parent->_right = child->_left;//过继子树
		child->_left = parent;//重构树结构
		Node* grandParent = parent->_parent;//维护祖父节点
		child->_parent = grandParent;//维护_parent
		parent->_parent = child;//维护_parent
		if (grandParent)//如果不是根节点
		{
			//维护祖父节点的子树
			if (parent == grandParent->_left) grandParent->_left = child;
			else grandParent->_right = child;
		}

		//维护平衡因子
		if (child->_bf == 1)
		{
			child->_bf = 0;
			parent->_bf = 0;
		}
		else if (child->_bf == 0)
		{
			assert(false);//不存在的情况
		}
		else
		{
			assert(false);//需要多次旋转时不应该调用该函数
		}
		if (parent == _root)
		{
			_root = child;//更新根节点
		}
	}

private:
	void RotateLR(Node* parent)
	{
		if (parent == nullptr) return;//错误情况
		Node* Lchild = parent->_left;
		if (Lchild == nullptr) return;//错误情况
		Node* Rchild = Lchild->_right;

		//先旋转左子树

		//维护树结构
		Lchild->_right = Rchild->_left;
		Rchild->_left = Lchild;
		Lchild->_parent = Rchild;
		parent->_left = Rchild;
		Rchild->_parent = parent;

		//维护_bf
		if (Lchild->_bf == 1)
		{
			Lchild->_bf = -1;
		}
		else
		{
			//_bf == -1 或 0都是非法的
			assert(false);
		}

		//再向右旋转
		Node* child = parent->_left;
		
		//维护树结构
		parent->_left = child->_right;
		child->_right = parent;

		Node* grandParent = parent->_parent;
		child->_parent = grandParent;
		parent->_parent = child;

		if (grandParent)//不是根节点
		{
			if (parent == grandParent->_left)grandParent->_left = child;
			else grandParent->_right = child;
		}

		//维护_bf
		parent->_bf = -1;
		child->_bf = 0;
		
		if (parent == _root)
		{
			_root = child;//更新根节点
		}
	}

private:
	void RotateRL(Node* parent)
	{
		//先向右旋转子树
		Node* Rchild = parent->_right;
		Node* Lchild = Rchild->_left;

		//维护树结构
		Rchild->_left = Lchild->_right;
		Lchild->_right = Rchild;
		Rchild->_parent = Lchild;
		Lchild->_parent = parent;
		parent->_right = Lchild;

		//维护_bf
		if (Rchild->_bf == -1)
		{
			Rchild->_bf = 0;
		}
		else
		{
			assert(false);//非法的情况
		}

		//再向左旋转
		Node* child = parent->_right;

		parent->_right = child->_left;//过继左子树
		child->_left = parent;
		parent->_parent = child;
		Node* grandParent = parent->_parent;
		child->_parent = grandParent;
		
		if (grandParent)//如果不是根节点
		{
			if (parent == grandParent->_left)grandParent->_left = child;
			else grandParent->_right = child;
		}

		//维护_bf
		parent->_bf = -1;
		child->_bf = 0;

		if (parent == _root)
		{
			_root = child;//更新根节点
		}
	}

private:
	Node* _root;
};