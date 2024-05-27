#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

const int R = 100;
const double L = 16.0 / 1000.0;
const double C = 63000 * (1e-12);     

const double Us = 2;

double f0 = 1.0 / 2 / 3.1415926 / sqrt(L * C);


double Q = (1.0 / R) * sqrt(L / C);

double getnum(double f)
{
	double w = 2 * 3.1415926 * f;

	double Z = (w * L - (1.0 / w / C));

	double n = R * R + Z * Z;

	double I = Us / sqrt(n);

	return I;
}

double getI0(double f)
{
	double F = f / f0 - f0 / f;
	double d = 1 + Q * Q * F * F;
	return 1.0 / sqrt(d);
}

int main()
{
	vector<double> arr({ 2000,2500,3000,3800,4000,4220,4500,4800,5000,6000,8000});

	cout << f0 <<" "<<Q << endl;

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ": " << getnum(arr[i]) <<" "<<getI0(arr[i]) <<" f/f0:"<<arr[i]/f0 << endl;
	}

	return 0;
}