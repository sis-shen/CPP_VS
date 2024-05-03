#pragma once

#include "MyHashTable.h"

namespace sup
{
	template<class K, class V>
	class unordered_map
	{
		struct MapkeyOfT
		{
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};

	public:
		bool insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

	private:
		sup_hash_bucket::HashTable<K, pair<K,V>, HashFunc, MapkeyOfT> _ht;
	};
}