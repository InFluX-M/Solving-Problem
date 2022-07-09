#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int* a = new int[n];
	int* b = new int[n];

	int m = 101;
	int M = -101;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (m > a[i]) m = a[i];
		if (M < a[i]) M = a[i];
	}
	
	int nOMin = INT_MAX;
	for (int i = m - (n - 1) * k; i <= M; i++)
	{
		int nO = 0;
		for (int j = 0; j < n; j++)
		{
			nO += abs(a[j] - (i + (j * k)));
		}

		if (nOMin > nO) nOMin = nO;
	}

	cout << nOMin;

	delete[] a;
	delete[] b;
}