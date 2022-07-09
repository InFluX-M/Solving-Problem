#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long int

void sort(ll a[], int i);

int main()
{
	int n;
	cin >> n;
	ll* a = new ll[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, n);
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}

void sort(ll a[], int i)
{
	if (i == 1) return;
	sort(a, i - 1);

	int p = i-1;
	while (p > 0 && a[p-1] > a[p])
	{
		swap(a[p - 1], a[p]);
		p--;
	}

	return;
}