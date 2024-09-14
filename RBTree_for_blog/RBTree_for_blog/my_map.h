#pragma once
#include "RBTree.hpp"
#include "utility"

namespace sup
{
	template<class K,class V>
	class map
	{
	public:
		map()
			:_rbtree()
		{}

		map(const map& mp)//øΩ±¥ππ‘Ï
			:_rbtree(mp._rbtree)
		{}

		V& operator[](const K& key)
		{
			auto it = _rbtree.Find(key);
			if (it == _rbtree.end())
			{
				_rbtree.Insert(key, std::pair{ key,V() });
			}
			else
			{
				return *it;
			}
		}

		const V& operator[]
	
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