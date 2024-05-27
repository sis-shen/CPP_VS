#include <iostream>
#include <string>

using namespace std;

namespace sup
{
	template<class T>
	class SmartPtr
	{
	public:
		SmartPtr(T* ptr) :_ptr(ptr) {}

		~SmartPtr()
		{
			cout << "~SmartPtr" << endl;

			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr) :_ptr(ptr) {}

		~unique_ptr()
		{
			cout << "~unique_ptr" << endl;

			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		//C++11
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;
	private:
		////C++98
		////只声明不实现
		////限定为私有
		//unique_ptr(const unique_ptr<T>& up);
		//unique_ptr<T>& operator=(const unique_ptr<T>& up);
	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr) :_ptr(ptr),_pcount(new int(1)) {}

		shared_ptr(const shared_ptr <T>& sp) :_ptr(sp._ptr), _pcount(sp._pcount)
		{
			++(*_pcount);
		}

		~shared_ptr()
		{
			cout << "~SmartPtr" << endl;
			--(*_pcount);
			if(*_pcount == 0 and _ptr)
				delete _ptr;
			delete _pcount;
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr == sp._ptr) return *this;
			//清理原资源
			
			--(*_pcount);
			if (*_pcount == 0)
			{
				if(_ptr)
					delete _ptr;
				delete _pcount;
			}

			_ptr = sp._ptr;
			_pcount = sp._pcount;
			++(*_pcount);

			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
		int* _pcount = 0;
	};

}


//int main()
//{
//	sup::shared_ptr<string> sp1(new string("xxxxxxxxxxx"));
//	sup::shared_ptr<string> sp2(sp1);
//
//
//	return 0;
//}

struct ListNode
{
	int val;
	sup::shared_ptr<ListNode> _next;
	sup::shared_ptr<ListNode> _prev;

	~ListNode()
	{
		cout << "~ListNode" << endl;
	}
};

int main()
{
	sup::shared_ptr<ListNode> n1 = new ListNode;
	sup::shared_ptr<ListNode> n2 = new ListNode;

	n1->_next = n2;
	n2->_prev = n1;
	
	return 0;
}