#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct point
{
	string ch1;
	string ch2;
};
queue<point> p;
int main()
{
	point temp;
	temp.ch1 = "sorry";
	temp.ch2 = "-_-";
	p.push(temp);
	cout << p.front().ch1 << " " << p.front().ch2 << endl;
	return 0;
}