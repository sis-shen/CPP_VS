#pragma once

#include "RBTree.h"

namespace sup
{
	template <class T, class V>
	class map
	{
	public:
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, pair<const K, V>> _t;
	};

	void test_map()
	{
		map<int, int> m;
		int a[] = { 1,2,3,4,5 };

		for (auto e : a) m.insert(e);
	}
}