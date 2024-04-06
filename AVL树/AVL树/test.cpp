#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "AVLTree.h"
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

int main()
{
	testAVLTree2();
	return 0;
}