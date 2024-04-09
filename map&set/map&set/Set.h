#pragma once

#include "RBTree.h"

namespace sup
{
	template <class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K,SetKeyOfT> _t;
	};

	void test_set()
	{
		set<int> s;
		int a[] = { 1,2,3,4,5 };

		for (auto e : a) s.insert(e);
	}
}