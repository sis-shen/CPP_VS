#pragma once
#include "MyHashTable.h"
namespace sup
{
	template<class K,class Hash = HashFunc<K>>
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
		typedef typename sup_hash_bucket::HashTable<K, K, SetkeyOfT, Hash>::const_iterator iterator;
		typedef typename sup_hash_bucket::HashTable<K, K, SetkeyOfT, Hash>::const_iterator const_iterator;


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
		pair<iterator, bool>  insert(const K& key)
		{ 
			auto ret = _ht.Insert(key);
			return pair<iterator, bool>({ iterator(ret.first._node,ret.first._pht,ret.first._hashi),ret.second });
		}
	private:
		sup_hash_bucket::HashTable<K, K, SetkeyOfT,Hash> _ht;
	};
}
