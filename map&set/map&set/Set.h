#pragma once

#include "RBTree.h"

namespace sup
{
	template <class T>
	class set
	{
	public:
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K> _t;
	};

	void test_map()
	{
		set<int> s;
		int a[] = { 1,2,3,4,5 };

		for (auto e : a) s.insert(e);
	}
}