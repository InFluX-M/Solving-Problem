#include <iostream>
using namespace std;

#define ll long long int
int sumDigit(ll n);

int main()
{
	ll number;
	cin >> number;

	cout << sumDigit(number);
}

int sumDigit(ll n)
{
	if (n == 0) return 0;
	return (n % 10) + sumDigit(n / 10);
}