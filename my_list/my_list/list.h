#pragma once

#include <iostream>

namespace sup
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _val;

		_list_node(const T& val = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_val(val)
		{}
	};

	template<class T,class Ptr,class Ref>
	struct _list_iterator
	{
		typedef _list_iterator<T,Ptr,Ref> self;
		typedef _list_node<T>* node;

		node _ptr;
		_list_iterator(node ptr = nullptr)
			:_ptr(ptr)
		{}

		self& operator++()
		{
			_ptr = _ptr->_next;
			return *this;
		}

		self& operator--()
		{
			_ptr = _ptr->_prev;
			return *this;
		}

		Ref operator*()
		{
			return _ptr->_val;
		}

		bool operator!=(const self& it)
		{
			return _ptr != it._ptr
		}
		
	};

	template<class T>
	class list
	{
	public:
		typedef _list_node<T> link_node;
		typedef _list_node<T>* node;

		typedef _list_iterator<T, link_node*,T&> iterator;
		typedef const _list_iterator<T, const link_node*, const T&> const_iterator;

		list()
			:_head(nullptr)
		{
			_head = new link_node;//ÉÚ±øÎ»
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

		node getNode(const T& val)
		{
			node temp = new link_node(val);
			temp->_next = nullptr;
			temp->_prev = nullptr;
			return temp;
		}

		void push_back(const T& val)
		{
			node tail = _head->_prev;

			node tmp = new link_node(val);

			tmp->_next = _head;
			tmp->_prev = tail;
			tail->_next = tmp;
			_head->_prev = tmp;
		}



	private:
		node _head;
	};



}