#include <iostream>
#include <algorithm>
using namespace std;

//میانه صحیح

#define ll long long int

int main()
{
	ll n;
	cin >> n;
	
	ll * a = new ll[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);

	ll M;
	if (n % 2 == 0) M = a[n / 2-1];
	else M = a[n / 2];;

	ll nO = 0;

	for (int i = 0; i < n; i++) nO += abs(a[i] - M);

	cout << M << " " << nO;
}