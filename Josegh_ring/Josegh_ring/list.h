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

		bool operator==(const self& it)
		{
			return _ptr == it._ptr;
		}

		bool operator!=(const self& it)
		{
			return !operator==(it);
		}


	};


	template<class T>
	class list
	{
	public:
		typedef ListNode<T> node;
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		
		list()
		{
			empty_init();
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
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

		bool clear()
		{
			while (!empty())
			{
				pop_front();
			}
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

		bool erase(iterator it)
		{
			if (it == end()) return false;
			node* cur = it._ptr;
			node* prev = cur->_prev;
			node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;
			return true;
		}

		bool empty()
		{
			return _head->_next == _head;
		}

		void print_list()
		{
			auto cur = begin();
			while (cur != end())
			{
				cout << *cur << " ";
				++cur;
			}
			cout << endl;
		}

		iterator find(const T& value)
		{
			auto cur = begin();
			while (cur != end() and *cur != value)
			{
				++cur;
			}
			return cur;
		}

		bool insert(iterator it,const T& value)
		{
			if (it == end()) return false;
			node* cur = it->_ptr;
			node* next = cur->_next;

			node* new_node = new node(value);

			cur->_next = new_node;
			new_node->_prev = cur;
			new_node->_next = next;
			next->_prev = cur;
			return true;
		}
	private:
		void empty_init()//初始化对象
		{
			_head = new node;//创建哨兵位
			_head->_next = _head;
			_head->_prev = _head;
		}

	private:
		node* _head;
	};

}