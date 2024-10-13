#include "RBTree.hpp"
#include "avlTree.h"
class KOF
{
public:
	int operator()(int x)
	{
		return x;
	}
};

int main()
{
	RBTree<int, int, KOF> rbtree;
	//for (int i = 10; i >0; --i)
	//{
	//	std::cout << "开始插入:" << i << std::endl;
	//	rbtree.Insert(i);
	//	//avltree.Insert({i,i});
	//}
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "开始插入:" << i << std::endl;
		rbtree.Insert(i);
		//avltree.Insert({i,i});
	}


	RBTree<int,int,KOF>::iterator it = rbtree.end();
	
	for (--it; it != rbtree.begin(); --it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "RBTree: " << rbtree.Height() << std::endl;
	std::cout << "RBTree: " << rbtree.IsValidRBTree() << std::endl;

	return 0;
}