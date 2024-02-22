#pragma once
#include <iostream>
using namespace std;
//BinarySearchTree --BSTree
//SearchBinaryTree --SBTree

template<class K>
struct BSTreeNode
{
	BSTreeNode(const K& k)
		:_key(k)
		,_left(nullptr)
		,_right(nullptr)
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

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	bool Find(const K& k)
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
			parent = cur;
			if (cur->_key < key)
				cur = cur->_right;
			else if (cur->_key > key)
				cur = cur->_left;
			else
			{

				//左为空
				if (cur->_left == nullptr)
				{
					if (parent->_left == cur)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;

					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (parent->_left == cur)
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

private:
	Node* _root = nullptr;
};

