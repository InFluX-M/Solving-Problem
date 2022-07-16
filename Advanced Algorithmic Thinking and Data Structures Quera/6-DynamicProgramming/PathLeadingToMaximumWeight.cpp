#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m;

#define ll long long int
void reverseStr(string& str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}
int main()
{
	cin >> n >> m;

	vector<vector<ll>> dp;
	vector<vector<ll>> a;
	vector<vector<string>> path;

	for (int i = 0; i < n; i++)
	{
		vector<ll> temp;
		vector<string> temp1;
		vector<ll> temp2;

		for (int j = 0; j < m; j++)
		{
			temp.push_back(-10000000000);
            temp1.push_back("");
		    int t;
			cin >> t;
			temp2.push_back(t);
		}

		dp.push_back(temp);
        path.push_back(temp1);
		a.push_back(temp2);

	}

	dp[n - 1][0] = a[n - 1][0];

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 && j == m - 1) break;

			if (i == 0)
			{
				if (dp[i][j] + a[i][j + 1] > dp[i][j + 1])
				{
					dp[i][j + 1] = dp[i][j] + a[i][j + 1];
					path[i][j + 1] = "R";
				}
			}
			else if (j == m - 1)
			{
				if (dp[i][j] + a[i - 1][j] > dp[i - 1][j])
				{
					dp[i - 1][j] = dp[i][j] + a[i - 1][j];
					path[i - 1][j] =  "U";
				}
			}
			else
			{
				if (dp[i][j] + a[i][j + 1] > dp[i][j + 1])
				{
					dp[i][j + 1] = dp[i][j] + a[i][j + 1];
					path[i][j + 1] = "R";
				}
				if (dp[i][j] + a[i - 1][j] > dp[i - 1][j])
				{
					dp[i - 1][j] = dp[i][j] + a[i - 1][j];
					path[i - 1][j] = "U";
				}
			}
		}
	}

	string p = "";

	int i = 0, j = m - 1;
	while (i != n-1 || j != 0)
	{
		p += path[i][j];

		if (path[i][j] == "R")
		{
			j--;
		}
		else
		{
			i++;
		}
	}


	cout << dp[0][m - 1] << "\n";
	reverseStr(p);
	cout << p;

}