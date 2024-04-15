#define  _CRT_SECURE_NO_WARNINGS 1
#include "Gragh.h"
#include <string>

void TestGraghMinTree()
{
	const char* str = "abcdefghi";
	Gragh<char, int> g(str, strlen(str));
	g.ADDEdge('a', 'b', 4);
	g.ADDEdge('a', 'h', 8);
	g.ADDEdge('b', 'c', 8);
	g.ADDEdge('b', 'h', 11);
	g.ADDEdge('c', 'i', 2);
	g.ADDEdge('c', 'f', 4);
	g.ADDEdge('c', 'd', 7);
	g.ADDEdge('d', 'f', 14);
	g.ADDEdge('d', 'e', 9);
	g.ADDEdge('e', 'f', 10);
	g.ADDEdge('f', 'g', 2);
	g.ADDEdge('g', 'h', 1);
	g.ADDEdge('g', 'i', 6);
	g.ADDEdge('h', 'i', 7);


}

void testGraghDijkstra()
{
	const char* str = "syztx";
	Gragh<char, int, INT_MAX, true> g(str, strlen(str));
	g.ADDEdge('s', 't', 10);
	g.ADDEdge('s', 'y', 5);
	g.ADDEdge('y', 't', 3);
	g.ADDEdge('y', 'x', 9);
	g.ADDEdge('z', 's', 7);
	g.ADDEdge('z', 'x', 6);
	g.ADDEdge('t', 'y', 2);
	g.ADDEdge('t', 'x', 1);
	g.ADDEdge('x', 'z', 4);

	vector<int> dist;
	vector<int> parentPath;
	g.Dijkstra('s', dist, parentPath);
	g.PrintShortPath('s', dist, parentPath);
}


int main()
{
	testGraghDijkstra();
	return 0;
}