#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <math.h>
using namespace std;


int main()
{
	long long int n;
	cin >> n;

	vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
	vector<int> des;
	for (int i = 0; i <= n; i++)
	{
		long long int t;
		cin >> t;
		des.push_back(t);
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			long long int minS = 10000000000000;
			for (int k = j; k < i; k++)
			{
				long long int res = dp[j][k] + dp[k+1][i] + des[j] * des[k+1] * des[i+1];
				minS = min(minS, res);
			}
			dp[j][i] = minS;
		}
	}
	
	cout << dp[0][n - 1];
}
