#include "Date.h"
using namespace std;
int main()
{
	int y, m, d;
	cout << "请输入起始年月日，空格分隔: ";
	cin >> y >> m >> d;

	Date date(y, m, d);
	while (true)
	{
		getchar();
		date.Print();
		++date;
	}
	return 0;
}