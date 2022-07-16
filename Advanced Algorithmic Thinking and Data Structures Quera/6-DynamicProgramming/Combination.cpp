#include <iostream>
using namespace std;

#define ll long long int
ll** dp = new ll * [2000 + 1];
ll c(ll n, ll r);

int main()
{
	for (int i = 0; i <= 2000; i++) dp[i] = new ll[2000 + 1];

	for (int i = 0; i <= 2000; i++) for (int j = 0; j <= 2000; j++) dp[i][j] = 0;

	int q;
	cin >> q;

	int** input = new int* [q];
	for (int i = 0; i < q; i++) input[i] = new int[2];
	int maxN = -1;
	for (int t = 0; t < q; t++)
	{
		cin >> input[t][0] >> input[t][1];
		if (input[t][0] > maxN) maxN = input[t][0];
	}

	for (int i = 0; i <= maxN; i++)
		for (int j = 0; j <= i; j++)
			dp[i][j] = c(i, j);

	for (int t = 0; t < q; t++)
	{
		cout << dp[input[t][0]][input[t][1]] << "\n";
	}

	delete[] dp;

}

ll c(ll n, ll r)
{
	if (n == r || r == 0)
	{
		dp[n][r] = 1;
		return 1;
	}

	dp[n][r] = (dp[n - 1][r] + dp[n - 1][r - 1]) % (1000000000 + 7);
	return dp[n][r];

}