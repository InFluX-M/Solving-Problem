#include <iostream>
#include <vector>
using namespace std;
int n, m;

#define ll long long int
vector<vector<ll>> dp;
vector<vector<ll>> a;

int main()
{
	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		vector<ll> temp;

		for (int j = 0; j < m; j++)
		{
			temp.push_back(10000000000);
		}

		dp.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		vector<ll> temp;

		for (int j = 0; j < m; j++)
		{
			ll t;
			cin >> t;
			temp.push_back(t);
		}

		a.push_back(temp);
	}


	dp[0][0] = a[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == n - 1 && j == m - 1) break;

			if (i == 0 && j == 0)
			{
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j+1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			}
			else if (i == 0 && j == m - 1)
			{
				dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + a[i][j - 1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			}
			else if (i == n - 1 && j == 0)
			{
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
			}
			else if (j == 0)
			{
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			}
			else if (j == m - 1)
			{
				dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + a[i][j - 1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			}
			else if (i == n - 1)
			{
				dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + a[i][j - 1]);
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
			}
			else
			{
				dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + a[i][j - 1]);
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
				dp[i + 1][j] = min(dp[i][j] + a[i + 1][j], dp[i + 1][j]);
			}
		}
		
		for (int j = 0; j < m; j++)
		{
			if (i == n - 1 && j == m - 1) break;

			if (i == 0 && j == 0)
			{
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j+1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			}
			else if (i == 0 && j == m - 1)
			{
				dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + a[i][j - 1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			}
			else if (i == n - 1 && j == 0)
			{
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
			}
			else if (j == 0)
			{
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			}
			else if (j == m - 1)
			{
				dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + a[i][j - 1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			}
			else if (i == n - 1)
			{
				dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + a[i][j - 1]);
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
			}
			else
			{
				dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + a[i][j - 1]);
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
				dp[i + 1][j] = min(dp[i][j] + a[i + 1][j], dp[i + 1][j]);
			}
		}
	}

	cout << dp[n - 1][m - 1];

}