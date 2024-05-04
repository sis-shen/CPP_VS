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

	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T,class Ref,class Ptr, class KeyOfT, class Hash = HashFunc<K> >
	struct __HTIterator
	{
		typedef hashNode<T> Node;
		typedef __HTIterator<K, T, Ref,Ptr,KeyOfT, Hash> Self;

		Node* _node;  
		HashTable<K, T, KeyOfT, Hash>* _pht;
		size_t _hashi;

		__HTIterator(Node* node, HashTable<K, T, KeyOfT, Hash>* pht,size_t hashi)
			:_node(node),_pht(pht),_hashi(hashi)
		{}

		__HTIterator(const __HTIterator<K, T,T&, 
			T*, KeyOfT, Hash>& self)
			:_node(self._node),_pht(self._pht),_hashi(self._hashi)
		{}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				//Hash hf;
				//KeyOfT kot;
				//size_t hashi = hf(kot(_node->_data)) % _pht->_tables.size() + 1;
				//while (hashi < _pht->_tables.size() && _pht->_tables[hashi] == nullptr) hashi++;
				//if (hashi == _pht->_tables.size())
				//	_node = nullptr;
				//else
				//	_node = _pht->_tables[hashi];
				++_hashi;
				while (_hashi < _pht->_tables.size() and _pht->_tables[_hashi] == nullptr) _hashi++;
				if (_hashi == _pht->_tables.size())
					_node = nullptr;
				else
					_node = _pht->_tables[_hashi];
			}

			return *this;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(_node->_data);
		}
	};

	template<class K, class T, class KeyOfT, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef hashNode<T> Node;

		template<class K, class T,class Ref,class Ptr ,class KeyOfT, class Hash>
		friend struct __HTIterator;
	public:
		typedef typename __HTIterator<K, T,T&,T*, KeyOfT, Hash> iterator;
		typedef typename __HTIterator<K, T,const T&,const T*, KeyOfT, Hash> const_iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], this, i);
				}
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this, -1);
		}
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

		pair<iterator,bool> Insert(const T& data)
		{
			KeyOfT kft;
			iterator it = Find(kft(data));
			if (it != end())
				return {it,false};

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
						cur->_next = newTables[hashi];//头插
						newTables[hashi] = cur;

						cur = next;
					}
					
					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}
			size_t hashi = hf(kft(data)) % _tables.size();
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_cnt;
			return {iterator(newnode,this,hashi),true};
		}

		iterator Find(const K& key)
		{
			KeyOfT kft;
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kft(cur->_data) == key)
				{
					return iterator(cur, this, hashi);
				}

				cur = cur->_next;
			}

			return end();
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