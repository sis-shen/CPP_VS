#pragma once
#include "MyHashTable.h"
namespace sup
{
	template<class K>
	class unordered_set
	{
		struct SetkeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}
	private:
		sup_hash_bucket::HashTable<K, K,HashFunc,SetkeyOfT> _ht;
	};
}
