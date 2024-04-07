#pragma once
//双向循环带头链表

namespace list
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _value;

		ListNode(const T& value = T())
			:_next(nullptr)
			,_prev(nullptr)
			,T(value)
		{}

	};

	template <class T,class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_iterator<T, Ref, Ptr> self;
		typedef ListNode<T> node;

		node* _ptr;

		_list_iterator(const node* ptr = nullptr)
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
			return _ptr->_value;
		}

		Ptr operator->()
		{
			return &(_ptr->_value);
		}


	};


	template<class T>
	class list
	{
	public:
		typedef ListNode<T> node;
		
		list()
		{
			_head = new node;//创建哨兵位
			_head->_next = _head;
			_head->_prev = _head;
		}

		bool push_front(const T& value)
		{
			node* new_node = new node(value);
			if (new_node == nullptr) return false;

			node* next = _head->_next;//新建一个临时变量，所有情况同时处理
			_head->_next = new_node;
			new_node->_prev = _head;
			new_node->_next = next;
			next->_prev = new_node;

			return true;
		}

		bool push_back(const T& value)
		{
			node* new_node = new node(value);
			if (new_node == nullptr) return false;

			node* prev = _head->_prev;
			_head->_prev = new_node;
			new_node->_next = _head;
			prev->_next = new_node;
			new_node->_prev = prev;

			return true;
		}

		bool pop_front()
		{
			if (empty()) return false;

			node* cur = _head->_next;

			_head->_next = cur->_next;
			cur->_next->_prev = _head;

			delete cur;
			return true;
		}

		bool pop_back()
		{
			if (empty()) return false;
			
			node* cur = _head->_prev;

			_head->_prev = cur->_prev;
			cur->_prev->_next = _head;

			delete cur;
			return true;
		}

		bool empty()
		{
			return _head->_next == _head;
		}

	private:
		node* _head;
	};

}