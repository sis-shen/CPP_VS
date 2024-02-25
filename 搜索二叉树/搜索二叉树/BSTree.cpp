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

	for (auto e : arr)
	{
		tree.Erase(e);
		tree.InOrder();
	}
}

int main()
{
	TestBSTree();
	return 0;
}