#include "BSTree.h"
#include <string>
using namespace std;

void TestBSTree()
{
	//                 8
	//            3          10
	//         1     6            14
	//            4    7         13
	int arr[] = { 8,3,1,10,6 ,4,7,14,13 };
	key::BSTree<int> tree;

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

void TestKeyTree()
{
	key_value::BSTree<string, string> dict;
	dict.Insert("sort", "ÅÅÐò");
	dict.Insert("order", "Ë³Ðò");
	dict.Insert("left", "ÓÒ±ß");
	dict.Insert("right", "ÓÒ±ß");
	dict.Insert("find", "²éÕÒ");
	dict.Insert("erase", "É¾³ý");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << ":" << ret->_value << endl;
		}
		else
		{
			cout << "ÎÞ´Ëµ¥´Ê" << endl;
		}
	}

}

int main()
{
	TestKeyTree();
	return 0;
}