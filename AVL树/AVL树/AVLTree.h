#pragma once
#include <utility>
#include <cassert>

template <class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	std::pair<K, V> _kv;
	int _bf;// ballance factor

	AVLTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
	typedef std::pair<K,V> PKV;
public:
	bool Insert(const PKV& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}

		cur->_parent = parent;

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 1 or parent->_bf == -1)
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 or parent->_bf == -2)
			{
				//需要旋转处理

				if (parent->_bf == 2 and cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 and cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 and cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 and cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else
					assert(false);

				break;//旋转完了就结束
			}
			else
			{
				assert(false);
			}
		}
	}

	void Print()
	{
		;
	}

	void Inorder()
	{
		_Inorder(_root);
		std::cout << std::endl;
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}


private:
	int _Height(Node* root)
	{
		if (root == nullptr) return 0;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		if (rightH - leftH != root->_bf)
		{
			std::cout << root->_kv.first << "平衡因子异常" << std::endl;
		}

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr) return true;

		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);

		return std::abs(leftH - rightH) < 2
			and _IsBalance(root->_left)
			and _IsBalance(root->_right);
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr) return;

		_Inorder(root->_left);
		std::cout << root->_kv.second << " ";
		_Inorder(root->_right);
	}

	void RotateL(Node* parent)
	{
		Node* pparent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if(subRL)
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

		parent->_bf = subR->_bf = 0;
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
		
		parent->_bf = subL->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = -1;

		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else
			assert(false);
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);

		if (bf == -1)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}


	}


private:
	Node* _root = nullptr;
};
