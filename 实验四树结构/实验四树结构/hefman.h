#pragma once

namespace sup
{
	struct HTreeNode
	{
	public:
		char _ch;
		int _weight;
		HTreeNode* _left;
		HTreeNode* _right;

		HTreeNode(char ch = 0,int weight = 0)
			:_ch(ch)
			,_weight(weight)
			,_left(nullptr)
			,_right(nullptr)
		{}


	};

	class HTree
	{
	public:
		typedef HTreeNode node;
		HTree()
			:_root(nullptr)
		{}




	private:
		node* _root;
	};

}