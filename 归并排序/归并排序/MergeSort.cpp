#include <vector>
#include <iostream>
using namespace std;

template<class T>
void _MergeSort(vector<T>& arr, int left, int right, vector<T>& tmp)
{
	if (left >= right) return;
	int mid = (left + right) / 2;

	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);

	int cur1 = left;
	int cur2 = mid + 1;
	int cur = left;

	while (cur1 <= mid && cur2 <= right)
	{
		if (arr[cur1] < arr[cur2])
		{
			tmp[cur++] = arr[cur1++];
		}
		else
		{
			tmp[cur++] = arr[cur2++];
		}
	}

	while (cur1 <= left)
		tmp[cur++] = arr[cur1++];
	while (cur2 <= right)
		tmp[cur++] = arr[cur2++];

	for (int i = left; i <= right; i++)
		arr[i] = tmp[i];

}

template<class T>
void MergeSort(vector<T>& arr)
{
	vector<T>tmp(arr.size());
	_MergeSort(arr, 0, arr.size() - 1, tmp);
}

//int main()
//{
//	vector<int> arr({ 1,3,9,4,5,7,6,0,7 });
//	MergeSort(arr);
//	for (auto e : arr)cout << e << " ";
//	return 0;
//};