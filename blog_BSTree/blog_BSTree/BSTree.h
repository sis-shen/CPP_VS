#pragma once
#include <iostream>
#include <utility>

namespace key_value
{
	template<class K,class V>
	class BSTNode
	{
	public:
		BSTNode(const K& key = K(), const V& value = V())
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
		BSTNode<K, V>* _left;//指向左子树
		BSTNode<K, V>* _right;//指向右子树
		K _key;//储存键
		V _value;//储存值
	};

	template<class K,class V>
	class BSTree
	{
		typedef BSTNode<K, V> Node;//使用typedef简化代码
	public:
		BSTree() :_root(nullptr) {}//提供默认构造函数

		BSTree(const BSTree<K, V>& bst)
		{
			_root = copy(bst._root);
		}

		~BSTree()
		{
			destroy(_root);
		}

		bool insert(const K& key, const V& value)
		{
			if (_root == nullptr)//空树
			{
				_root = new Node(key, value);
				return true;
			}
			//====修改的部分====
			PNN pnn = _find(key);

			Node* cur = pnn.first;
			Node* parent = pnn.second;

			if (cur != nullptr)//该key已存在，插入失败
			{
				return false;
			}
			//================
			
			//此时cur为nullptr, parent为cur的结点
			if (key < parent->_key)parent->_left = new Node(key, value);
			else parent->_right = new Node(key, value);
			return true;//成功插入
		}

		void in_order()
		{
			_in_order(_root);//传入根结点
			std::cout << std::endl;
		}
	protected:
		void _in_order(Node* root)
		{
			if (root == nullptr) return;
			_in_order(root->_left);//先访问左结点
			std::cout << root->_value << " ";//再访问根结点
			_in_order(root->_right);//最后访问右结点
		}


	public:
		typedef std::pair< Node*, Node* > PNN;//简化代码
		bool find(const K& key)
		{
			return _find(key).first != nullptr;//检查是否找到
		}
	protected:
	
		PNN _find(const K& key)//返回PNN用于简化其它接口
		{
			if (_root == nullptr) return {nullptr,nullptr};
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (key < cur->_key)//key比当前节点小，往左子树走
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)//往右子树走
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					//找到key
					return { cur,parent };
				}
			}
			//没找到key,cur为nullptr
			return { nullptr,parent };
		}
	public:

		bool erase(const K& key)
		{
			if (_root == nullptr)return false;//空树无法删除
			if (_root->_key == key && _root->_left == nullptr && _root->_right == nullptr)//删除最后一个结点
			{
				delete _root;
				_root = nullptr;
			}
			PNN pnn = _find(key);
			Node* cur = pnn.first;
			Node* parent = pnn.second;
			if (cur == nullptr) return false;//没找到该结点

			//下面的cur必不为空
			if(cur->_left == nullptr)
			{
				if (cur == _root)//为根节点时要替换根节点
				{
					Node* right = _root->_right;
					delete _root;
					_root = right;
				}
				//没有左子树，则直接移除结点,右子树替代原结点
				if (cur == parent->_left) parent->_left = cur->_right;
				else parent->_right = cur->_right;
				delete cur;
			}
			else if (cur->_right == nullptr)
			{
				if (cur == _root)
				{
					Node* left = _root->_left;
					delete _root;
					_root = left;
				}
				//直接过继左子树
				if (cur == parent->_left)parent->_left = cur->_left;
				else parent->_right = cur->_left;
			}
			else 
			{
				//找到左子树的最右结点
				Node* _cur = cur->_left;
				Node* _parent = cur;
				while (_cur->_right != nullptr)
				{
					_parent = _cur;
					_cur = _cur->_right;
				}
				//移走结点
				if (_cur == _parent->_left) _parent->_left = nullptr;
				else _parent->_right = nullptr;
				//获取cur的左右结点,必须再移走结点后，否则可能出现指向自己的结点
				_cur->_left = cur->_left;
				_cur->_right = cur->_right;
				//代替cur的位置
				if (cur == _root)//删除根结点时
				{
					delete _root;
					_root = _cur;
				}
				else//删除普通结点时
				{
					if (cur == parent->_left) parent->_left = _cur;
					else parent->_right = _cur;
					delete cur;
				}

			}
			return true;
		}


	protected:
		Node* copy(Node* root)
		{
			if (root == nullptr) return nullptr;//递归出口
			Node* pnode = new Node(root->_key, root->_value);//复制结点
			pnode->_left = copy(root->_left);
			pnode->_right = copy(root->_right);
			return pnode;
		}

		void destroy(Node* root)
		{
			if (root == nullptr) return;
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}
	private:
		Node* _root;//指向根节点的指针作为成员变量
	};
}