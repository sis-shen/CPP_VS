#pragma once

namespace sup
{
	template<class ValueType>
	struct Node
	{
		ValueType _val;
		Node<ValueType>* _next;
		Node<ValueType>* _prev;

		Node(const ValueType val = ValueType()):_val(val),_next(nullptr),_prev(_nullptr)
		{}

	};

	template<class ValueType>
	class list
	{
	public:
		typedef Node<ValueType> node;

		list()

	private:
		node* _head;
	};


}