#include "BSTree.h"
using namespace std;

void TestBSTree()
{
	//                 8
	//            3          10
	//         1     6            14
	//            4    7         13
	int arr[] = { 8,3,1,10,6 ,4,7,14,13 };
	BSTree<int> tree;

	for (auto e : arr)
	{
		tree.Insert(e);
	}

	tree.InOrder();

	tree.Erase(13);
	tree.InOrder();

	tree.Erase(14);
	tree.InOrder();

	tree.Erase(10);
	tree.InOrder();

	tree.Erase(8);
	tree.InOrder();
}

int main()
{
	TestBSTree();
	return 0;
}