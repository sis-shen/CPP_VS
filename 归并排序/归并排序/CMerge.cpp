#include <stdio.h>
#include <stdlib.h>

void _MergeSort(int* arr, int sz, int left, int right, int* tmp)
{
	if (left >= right) return;

	int mid = (left + right) / 2;

	_MergeSort(arr,sz ,left, mid, tmp);
	_MergeSort(arr, sz, mid + 1,right, tmp);
	int cur1 = left, cur2 = mid + 1, cur = left;

	while (cur1 <= mid && cur2 <= right)
	{
		if (arr[cur1] < arr[cur2])
			tmp[cur++] = arr[cur1++];
		else
			tmp[cur++] = arr[cur2++];
	}

	while (cur1 <= mid)
		tmp[cur++] = arr[cur1++];
	while (cur2 <= right)
		tmp[cur++] = arr[cur2++];

	for (int i = left; i <= right; i++)
		arr[i] = tmp[i];
}

void MergeSort(int* arr, int sz)
{
	int* tmp = (int*)malloc(sizeof(int) * sz);
	_MergeSort(arr, sz, 0, sz - 1, tmp);
}

int main()
{
	int arr[] = { 1,3,9,4,2,1,2,0,8 };
	MergeSort(arr,sizeof(arr)/sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}