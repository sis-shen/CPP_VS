#pragma once
#include <string>
#include <iostream>
using namespace std;

template <class T>//先用模板创建一个节点类
struct ListNode
{
	T _val;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	//提供全缺省的默认构造函数
	ListNode(const T& val = T()) :_val(val), _next(nullptr), _prev(nullptr) {}
};

template<class T,class Ref,class Ptr>//迭代器也得用模板
struct __list_iterator
{
	typedef __list_iterator<T,Ref,Ptr> Self;//简化代码
	typedef __list_iterator<T, T&, T*> iterator;
	typedef ListNode<T> Node;
	Node* _node;

	__list_iterator(Node* node) :_node(node) {}

	__list_iterator(iterator it) :_node(it._node) {}

	Self& operator++()//重载operator++
	{
		_node = _node->_next;
		return *this;
	}

	bool operator!=(const Self& it) const //重载!==,比较操作符记得加const
	{
		return _node != it._node;
	}

	Ref operator*()//重载 *
	{
		return _node->_val;
	}

	Ptr operator->()
	{
		return &(_node->_val);
	}
};

//用ListNode构造list类

template <class T>
class list
{
	typedef ListNode<T> Node;//用typedef简化代码
public:
	typedef __list_iterator<T,T&,T*> iterator;
	typedef __list_iterator<T,const T&,const T*> const_iterator;
public:
	list()//默认构造函数
	{
		_head = new Node;
		//维护两个指针
		_head->_next = _head;
		_head->_prev = _head;
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}

	void push_front(const T& val)
	{
		Node* newnode = new Node(val);
		Node* next = _head->_next;//额外的指针，简化代码

		_head->_next = newnode;
		newnode->_prev = _head;
		newnode->_next = next;
		next->_prev = newnode;
	}

	void pop_front()
	{
		if (empty()) return;

		Node* cur = _head->_next;
		
		_head->_next = cur->_next;
		cur->_next->_prev = _head;
		delete cur;
	}

	bool empty()
	{
		return _head->_next == _head;
	}

	//剩余代码自行补全

private:
	Node* _head;
};