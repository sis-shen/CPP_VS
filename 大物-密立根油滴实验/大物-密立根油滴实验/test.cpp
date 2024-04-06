#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;

int main()
{

	double member = 1.43e-14;
	double e0 = 1.602e-19;

	while (true)
	{
		double t = 0, U = 0;
		cout << "输入时间（秒），电压: ";
		scanf("%lf %lf", &t, &U);

		double tmp = 1.0 + 0.02 * pow(t, 0.5);
		tmp = t * tmp;
		tmp = pow(tmp, 1.5);

		double ret = member / tmp / U;
		int n = round(ret / e0);

		double e = ret / n;
		cout << "q:" << ret << " | n=" << n<<" | e="<<e << endl<<endl;
	}

	return 0;
}