#include <iostream>
#include <map>
#include <set>

using namespace std;

void testmap()
{
	map<int, int> dic;
	dic.insert(make_pair(1, 1));
	dic.insert({ 2,2 });

	for (auto e : dic)
	{
		cout << e.second << endl;
	}
}


int main()
{
	testmap();

	return 0;
}