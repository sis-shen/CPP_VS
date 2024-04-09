#pragma once

#include "RBTree.h"

namespace sup
{
	template <class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		//bool insert(const K& key)
		//{
		//	return _t.Insert(key);
		//}
	private:
		RBTree<K, pair<const K, V>,MapKeyOfT> _t;
	};

	//void test_map()
	//{
	//	map<int, int> m;
	//	int a[] = { 1,2,3,4,5 };

	//	for (auto e : a) m.insert(e);
	//}
}