#pragma once


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



	template<class T,class Ref>
	struct _list_iterator
	{
		typedef _list_iterator<T,Ref> self;
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

		bool operator!=(const self& it) const
		{
			return _ptr != it._ptr;
		}
		
	};

	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator,Ref,Ptr> self;
		typedef _list_node<T>* node;

		Reverse_iterator(node ptr = nullptr) :_it(ptr) {}

		Ref operator*()
		{
			return *_it;
		}

		Ptr operator->()
		{
			return _it.operator->();
		}

		self operator++()
		{
			return --_it;
		}

		self operator--()
		{
			return ++_it;
		}

		Iterator _it;
	};

	template<class T>
	class list
	{
	public:
		typedef _list_node<T> link_node;
		typedef _list_node<T>* node;

		typedef _list_iterator<T,T&> iterator;
		typedef _list_iterator<T, const T&> const_iterator;

		list()
			:_head(nullptr)
		{
			_head = new link_node;//ÉÚ±øÎ»
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(const_iterator first, const_iterator last)
		{
			EmptyInit();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(iterator first, iterator last)
		{

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list& lst)
		{
			EmptyInit();
			list tmp(lst.begin(), lst.end());
			swap(tmp);
		}

		void swap(list& tmp)
		{
			std::swap(_head, tmp._head);
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;

		}

		void clear()
		{
			node cur = _head->_next;
			while (cur != _head)
			{
				node next = cur->_next;
				delete cur;
				cur = next;
			}

			_head->_next = _head;
			_head->_prev = _head;
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}


		iterator end() 
		{
			return iterator(_head);
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

	protected:
		void EmptyInit()
		{
			_head = new link_node;//ÉÚ±øÎ»
			_head->_next = _head;
			_head->_prev = _head;
		}

	};



}