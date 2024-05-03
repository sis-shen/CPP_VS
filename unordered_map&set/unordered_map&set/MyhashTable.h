#pragma once

#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

//特化
template<>
struct HashFunc<string>
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

namespace sup_closed_address
{
	enum Status
	{
		EMPTY,
		EXIST,
		DELETE
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
			//f负载因子
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
					cout << "[" << i << "]->" << _tables[i]._kv.second << endl;
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

namespace sup_hash_bucket
{
	template<class T>
	struct hashNode
	{
		hashNode(const T& data) :_next(nullptr), _data(data) {}

		hashNode<T>* _next;
		T _data;
	};

	template<class K, class T, class Hash = HashFunc<K>,class KeyOfT>
	class HashTable
	{
		typedef hashNode<T> Node;
	public:
		HashTable() :_cnt(0)
		{
			_tables.resize(10);
		}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		bool Insert(const T& data)
		{
			KeyOfT kft;
			if (Find(kft(data))
				return false;

			Hash hf;
			
			if (_cnt == _tables.size())
			{
				vector<Node*> newTables;
				newTables.resize(_tables.size() * 2, nullptr);

				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hf(kft(cur->_data)) % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}
					
					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}
			size_t hashi = hf(kft(data)) % _tables.size();
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_cnt;
			return true;
		}

		Node* Find(const K& key)
		{
			KeyOfT kft;
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kft(cur->_data) == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			KeyOfT kft;
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kft(cur->_data) == key)
				{
					if (prev)
					{
						prev->_next = cur->_next;
						delete cur;
					}
					else
					{
						_tables[hashi] = cur->_next;
						delete cur;
					}
					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}

		void Print()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				cout << "[" << i << "]->";
				Node* cur = _tables[i];
				while (cur)
				{
					cout << cur->_kv.second << "->";
					cur = cur->_next;
				}
				cout << "N" << endl;
			}
		}
	private:
		vector<Node*> _tables;
		size_t _cnt = 0;
	};
}