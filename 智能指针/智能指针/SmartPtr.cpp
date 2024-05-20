#include <iostream>

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
}


int main()
{
	return 0;
}