#include <iostream>

using namespace std;

int main()
{
	long long cnt = 202420242020;
	long long num = 202420242020 / 10 * 120+1;
	long long t = 202420242024;
	while (cnt < t)
	{
		if (num % 20 == 0 || num % 24 == 0)
		{
			cnt++;
			//printf("%d ", cnt);
			if (cnt == t)
				break;
		}
		num++;
	}
	printf("%lld", num);
	return 0;
}



//int main()
//{
//	for (int i = 1; i < 480; ++i)
//	{
//		if (i % 20 == 0 && i % 24 == 0)
//		{
//			cout << i << endl;
//		}
//	}
//	return 0;
//}