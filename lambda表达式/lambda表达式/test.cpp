#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	auto comp = [&](int a, int b)->bool{
		if (arr[a] > arr[b]) return true;
		else if (arr[a] == arr[b] and a > b) return true;
		return false;
	};
	queue<int,vector<int>,comp>

	return 0;
}