#pragma once

#include "MyHashTable.h"

namespace sup
{
	template<class K, class V,class Hash = HashFunc<K>>
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
		typedef typename sup_hash_bucket::HashTable<K, pair<const K, V>, MapkeyOfT, Hash>::iterator iterator;
		typedef typename sup_hash_bucket::HashTable<K, pair<const K, V>, MapkeyOfT, Hash>::const_iterator const_iterator;


		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

	public:
		pair<iterator, bool>  insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert({ key,V() });
			return ret.first->second;
		}
	private:
		sup_hash_bucket::HashTable<K, pair<const K,V>, MapkeyOfT, Hash> _ht;
	};
}