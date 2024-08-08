#include "BSTree.h"
#include <vector>
#include <utility>
using namespace std;


int main()
{
	vector<int> arr({ 2,3,1,5,4,6,8,7 });//准备待插入的键值对
	key_value::BSTree<int, int> bst;
	for (int i = 0; i < arr.size(); ++i)
	{
		bst.insert(arr[i],arr[i]);//这里使键值相同，方便观察
	}
	bst.erase(2);

	bst.in_order();//测试

	key_value::BSTree<int, int> copy(bst);


	//cout << bst.find(1);


	return 0;
}