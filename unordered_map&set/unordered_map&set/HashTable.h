#pragma once

#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace sup
{
	enum Status
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	struct HashFuncString
	{
		size_t operator()(const string& str)
		{
			size_t mode = 1e9 + 7;
			size_t base = 131;
			size_t hash = 0;
			for (auto e : str)
			{
				hash = hash * base % mode + e;
				hash %= mode;
			}
			return hash;
		}
	};

	template <class K,class V>
	struct HashData
	{
		HashData() :_s(EMPTY){};
		pair<K, V> _kv;
		Status _s;
	};

	template <class K,class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		typedef HashTable<K, V, Hash> Self;

		HashTable():_cnt(0)
		{
			_tables.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			Hash hf;
			if (Find(kv.first))
				return false;
			//f¸ºÔØÒò×Ó
			if (_cnt*1.0 / _tables.size() >= 0.7)
			{
				size_t newSize = _tables.size() * 2;
				Self newHT;
				newHT._tables.resize(newSize);
				for (int i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._s == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}

				_tables.swap(newHT._tables);
			}

			size_t hashi = hf(kv.first) % _tables.size();
			while (_tables[hashi]._s == EXIST)
			{
				hashi++;
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._s = EXIST;
			_cnt++;
			return true;
		}

		void Print()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._s == EXIST)
				{
					cout << "[" << i << "]->" << _tables[i].second << endl;
				}
				else if (_tables[i]._s == EMPTY)
				{
					cout << "[" << i << "]->" << endl;
				}
				else
				{
					cout << "[" << i << "]->D" << endl;
				}
			}
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			while (_tables[hashi]._s != EMPTY)
			{
				if (_tables[hashi]._s == EXIST
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				hashi++;
				hashi %= _tables.size();
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_s = DELETE;
				_cnt--;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<HashData<K,V>> _tables;
		size_t _cnt;
	};
}
