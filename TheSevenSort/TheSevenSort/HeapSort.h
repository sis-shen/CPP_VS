#pragma once
#include <vector>
using namespace std;

template<class T>
void adjust_up(vector<T>& arr, int child)
{
	int parent = (child - 1) / 2;
	while (parent != child)//parent == child == 0时
	{
		if (arr[parent] < arr[child])//不满足大堆
		{
			swap(arr[parent], arr[child]);//交换
			child = parent;//继续向上调整,迭代child和parent
			parent = (child - 1) / 2;
		}
		else//完成建堆，退出循环
		{
			break;
		}
	}
}

template<class T>
void adjust_down(vector<T>& arr,int sz , int parent)
{
	int child = parent * 2 + 1;
	if (child + 1 < sz && arr[child + 1] > arr[child]) child++;//取较大的孩子

	while (child < sz)
	{
		if (arr[parent] < arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			int child = parent * 2 + 1;
			if (child >= sz) break;
			if (child + 1 < sz && arr[child + 1] > arr[child]) child++;
		}
		else
		{
			break;
		}
	}
}

template <class T>
void heap_sort(vector<T>& arr)
{
	int sz = arr.size();

	//建堆
	for (int i = 1; i < sz; i++)
	{
		adjust_up(arr, i);//逐个插入并向上调整建堆
	}

	for (int i = sz-1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);//选出最大的元素放在末尾
		adjust_down(arr,i,0);//向下调整建堆
	}
}
