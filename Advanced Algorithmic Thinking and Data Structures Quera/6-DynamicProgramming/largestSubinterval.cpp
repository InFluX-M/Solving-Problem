#include <iostream>
using namespace std;

#define ll long long int


int main()
{
    int n;
    cin >> n;
    
    ll* dp = new ll[n];
	ll* a = new ll[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = 0;
		cin >> a[i];
	}

	dp[0] = a[0];

	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1] + a[i] > a[i]) dp[i] = dp[i - 1] + a[i];
		else dp[i] = a[i];
	}

	ll max = -1 * 10e9;
	for (int i = 0; i < n; i++)
	{
		if (max < dp[i]) max = dp[i];
	}
    
    delete[] a;
    delete[] dp;
    
	cout << max;
}
