#include "HashTable.h"

using namespace std;

void testHT()
{
	vector<int> arr({ 1,6,7,66,34,5,-19,54,20,40 });

	sup::HashTable<int, int> ht;
	for (auto e : arr)
	{
		ht.Insert({ e,e });
	}

	printf("\n\n\n");
	ht.Erase(1);
	ht.Insert({1,111});
}

void TestStrHT()
{
	vector<string> arr({ "Æ»¹û","éÙ×Ó","Ïã½¶","ÆÏÌÑ","·ïÀæ" });
	sup::HashTable<string, string> ht;
	for (auto str : arr)
	{
		ht.Insert({ str,str });
	}

	ht.Print();
}

int main()
{
	TestStrHT();
	return 0;
}