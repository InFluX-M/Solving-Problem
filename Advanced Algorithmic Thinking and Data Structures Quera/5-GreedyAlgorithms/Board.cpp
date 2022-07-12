#include <iostream>
#include <algorithm>

#define ll long long int

using namespace std;

int main()
{
	int n, c;
	cin >> n >> c;

	int* x = new int[n];
	for (int i = 0; i < n; i++) cin >> x[i];

	sort(x, x + n);

	int d = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		d = min(c, max(0, x[i] - c));
		c -= d;
	}

	cout << c;
}