#include "mylist.h"

using namespace std;

int main()
{
	list<int> lst;
	lst.push_front(5);
	lst.push_front(4);
	lst.push_front(3);
	lst.push_front(2);
	lst.push_front(1);

	for (auto e : lst)
	{
		cout << e << " ";
	}
	return 0;
}