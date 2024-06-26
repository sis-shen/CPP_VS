#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "AVLTree.h"
#include "RBTree.h"
using namespace std;

void testAVLTree1()
{
	AVLTree<int, int> avt;

	int arr[] = { 1,4,9,7,5,3,10};
	//int arr[] = { 3,2,1 };
	for (auto e : arr)
	{
		avt.Insert({ e,e });
	}

	avt.Inorder();

	cout << avt.IsBalance()<<endl;

}

void testAVLTree2()
{
	AVLTree<int, int> avt;

	srand((unsigned)time(NULL));
	//int arr[] = { 3,2,1 };
	const int N = 100;
	for (int i = 0 ;i<N;i++)
	{
		size_t x = rand();
		avt.Insert({ x,x });
	}

	avt.Inorder();

	cout << avt.IsBalance() << endl;

}

void testRBTree1()
{
	RBTree<int, int> rbtree;

	int arr[] = { 1,4,9,7,5,3,10,55,66,12,45,94 };
	//int arr[] = { 3,2,1 };
	for (auto e : arr)
	{
		rbtree.Insert({ e,e });
	}

	rbtree.Inorder();

	cout << rbtree.Check() << endl;

}

void testRBTree2()
{
	RBTree<int, int> rbtree;

	srand((unsigned)time(NULL));
	//int arr[] = { 3,2,1 };
	const int N = 100;
	for (int i = 0; i < N; i++)
	{
		size_t x = rand();
		rbtree.Insert({ x,x });
	}


	cout << rbtree.Check() << endl;

}

void testHeight()
{
	RBTree<int, int> rbtree;
	AVLTree<int, int> avltree;
	srand((unsigned)time(NULL));
	//int arr[] = { 3,2,1 };
	const int N = 10000000;
	for (int i = 0; i < N; i++)
	{
		size_t x = rand()+i;
		rbtree.Insert({ x,x });
		avltree.Insert({ x,x });
	}


	cout << rbtree.Height() << endl;
	cout << avltree.Height() << endl;

}

int main()
{
	testHeight();
	return 0;
}