#include <iostream>
using namespace std;


double division(int len, int time)
{
	if (time == 0)
	{
		throw "³ý0´íÎó";
	}
	else
	{
		return (double)len / time;
	}
}

void Func()
{
	int len, time;
	cin >> len >> time;
	cout << division(len, time) << endl;

}

int main()
{
	try
	{
		Func();
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	return 0;
}