#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "PriorityQueue.h"

int main()
{
	sup_priority::priority_queue<int> PQ;
	PQ.push(1);
	PQ.push(3);
	PQ.push(11);
	PQ.push(7);
	PQ.push(9);
	
	std::cout << PQ.top();
	return 0;
}