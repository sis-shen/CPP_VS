#include "MyunorderedMap.h"
#include "MyUnorderedSet.h"
using namespace std;
int main()
{
	sup::unordered_set<int> us;
	vector<int> arr({ 1,6,7,66,34,5,-19,54,20,40 });
	for (auto e : arr)
	{
		us.insert(e);
	}

	auto it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		++it;
	}
	return 0;
}