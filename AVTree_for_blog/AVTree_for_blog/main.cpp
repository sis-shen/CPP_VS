#include "AVLTree.hpp"
#include <iostream>
using namespace std;
int main()
{
	AVLTree<int,int> avt;
	for (int i = 0; i < 100; ++i)
	{
		avt.Insert({ i,i });
	}
	cout <<"Height " << avt.Height() << endl;
	cout << "IsBalance " << avt.IsBalance() << endl;
	avt.Inorder();
	return 0;
}