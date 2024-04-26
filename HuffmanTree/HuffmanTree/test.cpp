#define  _CRT_SECURE_NO_WARNINGS 1

#include "hefman.h"

void TestHefmanTree()
{
	string str = "abcdef";
	vector<char> ch(str.begin(), str.end());
	vector<int> weigh({ 9,8,7,6,5,4 });

	sup::HefmanTree<char>ht(ch, weigh);

	ht.print_tree();
	cout << endl;
	ht.print_code_list();
}


int main()
{
	TestHefmanTree();

	return 0;
}