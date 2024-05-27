#include <iostream>
#include "HeapSort.h"
using namespace std;

int main()
{
	vector<int> arr({ 5,3,20,17,16,4 });
	heap_sort(arr);
	for (auto e : arr)cout << e << " "; cout << endl;
	return 0;
}