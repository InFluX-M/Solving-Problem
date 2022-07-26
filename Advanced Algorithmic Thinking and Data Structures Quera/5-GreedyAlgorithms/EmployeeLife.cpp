#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);

	int nWork = 0;
	for (int i = 0; i < n; i++)
	{
		if (nWork < a[i]) nWork++;
	}

	cout << nWork;
}