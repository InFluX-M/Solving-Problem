#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
double power(double base, int exp);

int main()
{
	double base;
	int exp;

	cin >> base >> exp;

	cout << setprecision(3) << fixed << showpoint << power(base, exp);
}

double power(double base, int exp)
{
	if (exp == 0) return 1.0;
	if (exp == 1) return base;

	double res = power(base, exp / 2);

	if (exp % 2 == 0) return res * res;
	else return base * res * res;
}