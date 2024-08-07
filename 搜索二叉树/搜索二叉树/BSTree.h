#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
//BinarySearchTree --BSTree
//SearchBinaryTree --SBTree

namespace key
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode(const K& k)
			:_key(k)
			, _left(nullptr)
			, _right(nullptr)
		{
			;
		}

		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		~BSTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		BSTree() = default;//指定强制生成默认构造

		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* cur = _root;
			Node* prev = cur;
			while (cur)
			{
				prev = cur;
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			if (prev->_key < key)
				prev->_right = new Node(key);
			else
				prev->_left = new Node(key);

		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}



		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
					return true;
			}

			return false;
		}

		bool Erase(const K& key)
		{
			if (_root == nullptr) return false;
			if (_root->_key == key and _root->_left == nullptr and _root->_right == nullptr)
			{
				delete _root;
				_root = nullptr;
				return true;
			}

			Node* parent = _root;
			Node* cur = _root;

			while (cur)
			{

				if (cur->_key < key)
					parent = cur,
					cur = cur->_right;
				else if (cur->_key > key)
					parent = cur,
					cur = cur->_left;
				else
				{

					//左为空
					if (cur->_left == nullptr)
					{
						if (_root == cur)
							_root = cur->_right;
						else if (parent->_left == cur)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;

						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
							_root = cur->_left;
						else if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;

						delete cur;
					}
					else
					{
						//找左树的最大节点（最右边） 或 右树的最小节点
						Node* pmint_right = cur;
						Node* min_right = cur->_right;
						while (min_right->_left)
						{
							pmint_right = min_right;
							min_right = min_right->_left;
						}

						cur->_key = min_right->_key;
						if (pmint_right == cur)
							pmint_right->_right = min_right->_right;
						else
							pmint_right->_left = min_right->_right;
						delete min_right;

					}


					return true;
				}
			}

			return false;
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr) return false;
			if (root->_key == key) return true;

			if (root->_key < key) return _FindR(root->_right, key);
			else return _FindR(root->_left, key);
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}



		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}



		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	protected:
		Node* Copy(Node* root)
		{
			if (root == nullptr) return nullptr;

			Node* newRoot = new  Node(root->_key);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);
			return newRoot;

		}

		void Destroy(Node* root)
		{
			if (root == nullptr) return;

			Destroy(root->_left);
			Destroy(root->_right);

			delete root;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr) return false;

			if (root->_key < key) _EraseR(root->_right, key);
			else if (root->_key) _EraseR(root->_left, key);
			else
			{
				if (root->_left == nullptr) {
					auto del = root;
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr)
				{
					auto del = root;
					root = root->_left;
					delete del;
				}
				else
				{
					Node* max_left = root->_left;
					while (max_left->_right)
						max_left = max_left->_right;
					swap(root->_key, max_left->_key);

					_EraseR(root->_left, key);

				}

			}
			return true;

		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key > key)
				return _InsertR(root->_lef, key);
			else if (root->_key < key)
				return _InsertR(root->_right);
			else return false;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

	private:
		Node* _root = nullptr;
	};

}


namespace key_value
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode(const K& k,const V& value)
			:_key(k)
			, _left(nullptr)
			, _right(nullptr)
			,_value(value)
		{
			;
		}

		BSTreeNode<K,V>* _left;
		BSTreeNode<K,V>* _right;
		K _key;
		V _value;
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K,V> Node;
	public:
		~BSTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		

		BSTree() = default;//指定强制生成默认构造



		bool Insert(const K& key,const V& v)
		{
			if (_root == nullptr)
			{
				_root = new Node(key,v);
				return true;
			}

			Node* cur = _root;
			Node* prev = cur;
			while (cur)
			{
				prev = cur;
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			if (prev->_key < key)
				prev->_right = new Node(key,v);
			else
				prev->_left = new Node(key,v);

			return true;

		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}



		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
					return cur;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			if (_root == nullptr) return false;
			if (_root->_key == key and _root->_left == nullptr and _root->_right == nullptr)
			{
				delete _root;
				_root = nullptr;
				return true;
			}

			Node* parent = _root;
			Node* cur = _root;

			while (cur)
			{

				if (cur->_key < key)
					parent = cur,
					cur = cur->_right;
				else if (cur->_key > key)
					parent = cur,
					cur = cur->_left;
				else
				{

					//左为空
					if (cur->_left == nullptr)
					{
						if (_root == cur)
							_root = cur->_right;
						else if (parent->_left == cur)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;

						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
							_root = cur->_left;
						else if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;

						delete cur;
					}
					else
					{
						//找左树的最大节点（最右边） 或 右树的最小节点
						Node* pmint_right = cur;
						Node* min_right = cur->_right;
						while (min_right->_left)
						{
							pmint_right = min_right;
							min_right = min_right->_left;
						}

						cur->_key = min_right->_key;
						if (pmint_right == cur)
							pmint_right->_right = min_right->_right;
						else
							pmint_right->_left = min_right->_right;
						delete min_right;

					}


					return true;
				}
			}

			return false;
		}



	protected:
		Node* Copy(Node* root)
		{
			if (root == nullptr) return nullptr;

			Node* newRoot = new  Node(root->_key);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);
			return newRoot;

		}

		void Destroy(Node* root)
		{
			if (root == nullptr) return;

			Destroy(root->_left);
			Destroy(root->_right);

			delete root;
		}



		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

	private:
		Node* _root = nullptr;
	};

}

