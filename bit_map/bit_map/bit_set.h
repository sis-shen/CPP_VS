#pragma once
#include <vector>

using namespace std;

namespace sup
{
	template <size_t N = 10>
	class bit_set
	{
	public:
		bit_set():_bits(N/32+1,0)
		{}

		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_bits[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_bits[i] &= ~(1 << j);
		}

		bool test(size_t x)
		{

		}

	private:
		vector<int> _bits;
	};

	template <size_t N = 10>
	class twobit_set
	{
	public:
		void set(size_t x)
		{
			if (_bs1.test(x) == false && _bs2.test(x) == false)
			{
				_bs2.set(X);
			}
			else if (_bs1.test(x) == false and _bs2.test(x) == true)
			{
				_bs1.set(x);
				_bs2.reset(x)
			}
		}

	private:
		bit_set<N> _bs1;
		bit_set<N> _bs2;
	};
}
