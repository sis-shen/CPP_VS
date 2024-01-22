#pragma once

#include <vector>
#include <functional>

namespace sup_priority
{

	template<class T> 
	bool less(T e1, T e2)
	{
		return e1 < e2;
	}

	template<class T, class Containor = std::vector<T>, class Comp = std::less<T>>
	class priority_queue
	{
	public:

		void adjust_up(int child)
		{
			Comp cmp;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (cmp(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
				}
				child = parent;
				parent = (child - 1) / 2;
			}
		}

		void adjust_down(int parent)
		{
			Comp cmp;
			int child = parent * 2 + 1;
			if (child + 1 < size() and cmp(_con[child], _con[child + 1]))
			{
				child = child + 1;
			}

			while (child < size())
			{
				if (cmp(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);

				}
				parent = child;
				child = parent * 2 + 1;
				if (child + 1 < size() and cmp(_con[child], _con[child + 1]))
				{
					child = child + 1;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		size_t size()
		{
			return _con.size();
		}

		const T& top()
		{
			return _con[0];
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.size()--;
			adjust_down(0);
		}
	private:
		Containor _con;
	};
}