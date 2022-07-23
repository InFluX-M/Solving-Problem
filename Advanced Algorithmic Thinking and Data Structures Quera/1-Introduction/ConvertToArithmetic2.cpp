#include <iostream>
#include <algorithm>
using namespace std;

//تبدیل به حسابی ۲

#define ll long long int

int main()
{
	ll n, k;
	cin >> n >> k;

	ll* a = new ll[n];
	for (ll i = 0; i < n; i++) cin >> a[i];


	ll* b = new ll[n];
	for (int i = 0; i < n; i++) b[i] = a[i] - (i * k);
	sort(b, b + n);

	ll M;
	if (n % 2 == 0) M = b[n / 2 - 1];
	else M = b[n / 2];

	ll nO = 0;
	for (int i = 0; i < n; i++) nO += abs(b[i] - M);

	cout << nO;

}