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
	for (int i = 10; i >0; --i)
	{
		std::cout << "¿ªÊ¼²åÈë:" << i << std::endl;
		rbtree.Insert(i);
		//avltree.Insert({i,i});
	}
	rbtree.Inorder();
	std::cout << "RBTree: " << rbtree.Height() << std::endl;
	std::cout << "RBTree: " << rbtree.IsValidRBTree() << std::endl;

	return 0;
}