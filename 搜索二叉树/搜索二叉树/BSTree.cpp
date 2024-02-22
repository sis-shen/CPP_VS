#include "BSTree.h"
using namespace std;

void TestBSTree()
{
	int arr[] = { 8,3,1,10,6 ,4,7,14,13 };
	BSTree<int> tree;

	for (auto e : arr)
	{
		tree.Insert(e);
	}

	tree.InOrder();

	tree.Erase(4);
}

int main()
{
	TestBSTree();
	return 0;
}