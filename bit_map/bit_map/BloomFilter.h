#pragma once

#include <bitset>
using namespace std;



template <size_t N, class K, 
	class HashFunc1, 
	class HashFunc2,
	class HashFunc3>
class BloomFilter
{
public:

	void Set(const K& key)
	{
		size_t hash1 = HashFunc1()(key) % N;
		size_t hash2 = HashFunc2()(key) % N;
		size_t hash3 = HashFunc3()(key) % N;

		_bs.set(hash1);
		_bs.set(hash2);
		_bs.set(hash3);
	}

	bool Test(const K& key)
	{
		size_t hash1 = HashFunc1()(key) % N;
		if (_bs.test(hash1) == false)
			return false;

		size_t hash2 = HashFunc2()(key) % N;
		if (_bs.test(hash2) == false)
			return false;

		size_t hash3 = HashFunc3()(key) % N;
		if (_bs.test(hash3) == false)
			return false;
	}

private:
	bitset<N> _bs;
};
