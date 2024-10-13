#pragma once
#include "RBTree.hpp"
#include "utility"

namespace sup
{
	template<class K,class V>
	class map
	{
	public:
		typedef RBTree::iterator iterator;
		typedef RBTree::const_iterator const_iterator;
	public:
		map()
			:_rbtree()
		{}

		map(const map& mp)//øΩ±¥ππ‘Ï
			:_rbtree(mp._rbtree)
		{}

		V& operator[](const K& key)
		{
			std::pair<bool, iterator> PBI = _rbtree.Insert(key, std::pair{ key,V() });
			return *(PBI.second);
		}

		const V& operator[](const K&key) const
		{
			
		}
	
	private:
		class KeyOfValue
		{
		public:
			K operator()(std::pair<K, V> NodeValue)
			{
				return NodeValue.first;
			}
		};
	private:
		RBTree<K, std::pair<K,V>,KeyOfValue> _rbtree;
	};
}