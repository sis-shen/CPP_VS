#pragma once
#include <algorithm>


namespace slist
{
	template<class T>//定义链表节点，储存值的类型为T
	struct ListNode
	{
		ListNode<T>* _next;
		T _value;


		ListNode(const T& value = T())
			:_next(nullptr)
			, _value(value)
		{}
	};

	template <class T,class Ref,class Ptr>
	class _slist_iterator
	{
	public:
		typedef _slist_iterator<T,Ref,Ptr> self;
		typedef ListNode<T>* node;

		node _ptr;

		_slist_iterator(const node ptr=nullptr)
			:_ptr(ptr)
		{}

		self& operator++()
		{
			_ptr = _ptr->_next;
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

		bool operator!=(const self& it) const
		{
			return _ptr != it._ptr;
		}

	};

	template <class T>
	class slist
	{
	public:
		typedef ListNode<T> Node;
		typedef _slist_iterator<T,T&,T*> iterator;
		typedef _slist_iterator<T,const T&,const T*> const_iterator;

		slist()
		{
			EmptyInit();//使用封装的函数，可以复用
		}

		slist(const slist<T>& sl)//拷贝构造
		{
			slist<T> tmp(sl.begin(), sl.end());
			swap(tmp);
		}

		template<class Iterator>
		slist(Iterator first, Iterator end)
		{
			EmptyInit();//使用封装的函数，可以复用
			while (first != end)
			{
				PushBack(*first);
				++first;
			}
		}

		~slist()
		{
			Destroy();
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_tail->_next);
		}

		const_iterator begin() const
		{
			return (_head->_next);
		}

		const_iterator end() const
		{
			return (_tail->_next);
		}

	public:
		void PrintList()
		{
			iterator first = begin();
			while (first != end())
			{
				std::cout << *first << " ";
				++first;
			}
			std::cout << std::endl;
		}

		bool Erase(iterator it)
		{
			return Erase(it._ptr);
		}

		bool Erase(Node* ptr)
		{
			if (ptr == nullptr) return false;
			Node* prev = _head;
			Node* cur = _head->_next;
			while (cur and cur != ptr)
			{
				prev = cur;
				cur = cur->_next;
			}

			if (cur == nullptr) return false;

			prev->_next = cur->_next;
			delete cur;
			return true;
		}

		iterator Find(const T& value)
		{
			auto first = begin();
			while (first != end())
			{
				if (*first == value)
					return first;

				++first;
			}
			return end();
		}

		void swap(slist& sl)
		{
			std::swap(_head, sl._head);
			std::swap(_tail, sl._tail);
		}

		bool Destroy()
		{
			if (Empty()) return false;
			while (!Empty())
			{
				PopFront();
			}
			_tail = nullptr;
			_head = nullptr;

			return true;
		}

		bool PushFront(const T& value)
		{
			Node* newNode = new Node(value);
			if (newNode == nullptr) return false;

			Node* next = _head->_next;
			_head->_next = newNode;
			newNode->_next = next;
			if (_tail == _head) _tail = newNode;//尾插特例
			return true;
		}

		bool PushBack(const T& value)
		{
			Node* newNode = new Node(value);
			if (newNode == nullptr) return false;

			_tail->_next = newNode;
			_tail = newNode;
			_tail->_next = nullptr;//解耦合，防止ListNode的构造函数没给newNode->next初始化为nullptr
		}

		bool PopFront()
		{
			if (Empty()) return false;
			
			Node* cur = _head->_next;
			if (_tail == cur) _tail = _head;//先判断要改变_tail的情况

			_head->_next = cur->_next;
			delete cur;
			return true;
		}

		bool PopBack()
		{
			if (Empty()) return true;

			Node* cur = _head;
			while (cur->_next != _tail) cur = cur->_next;//找到尾指针前一个节点

			delete _tail;
			_tail = cur;
			_tail->_next = nullptr;
			return true;

		}

		bool Empty()
		{
			return _head == _tail;
		}

	private:
		void EmptyInit()
		{
			_head = new Node;//创建哨兵位
			_tail = _head;
		}

	private:
		Node* _head;
		Node* _tail;
	};
}

using namespace std;
#include <iostream>

void testRangeFor()
{
	int arr[] = { 1,2,3,4,5,6 };

	slist::slist<int> lst;

	for (auto e : arr)
	{
		lst.PushBack(e);
	}

	slist::slist<int> lst2(lst);

	for (auto num : lst2)
	{
		cout << num << " ";
	}
	cout << endl;
}

void testMain()
{
	//测试增删查改
	slist::slist<int> slst;
	slist::slist<int> copy(slst);

	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 10,9,8,7,6 };

	for (auto e : arr1) slst.PushBack(e);
	slst.PrintList();

	for (auto e : arr2) slst.PushFront(e);
	slst.PrintList();

	auto it = slst.Find(8);
	*it = 888;
	slst.PrintList();

	slst.Erase(it);
	slst.PrintList();

	int n = 5;
	while (n--) slst.PopBack();
	slst.PrintList();

	n = 4;
	while (n--) slst.PopFront();
	slst.PrintList();

}