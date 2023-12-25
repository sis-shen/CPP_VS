#pragma once

#include <cstdlib>
#include <cassert>

namespace sup
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;


		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{

		}

		iterator begin()
		{
			return _start;
		}
		const_iterator begin() const
		{
			return _start;
		}
		
		iterator end() const
		{
			return _finish;
		}

		const_iterator end()
		{
			return _finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		bool empty() const
		{
			return _start == _finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else 
			{
				if(n > capacity())
					reserve(n);

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		
		void insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish;
			while (end > pos)
			{
				*(end) = *(end - 1);
				--end;
			}

			*pos = val;
			++_finish;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					memcpy(tmp, _start, (sizeof(T) * size()));
					delete _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
				
			}
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}



		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;
			++_finish;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}