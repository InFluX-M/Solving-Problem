#include <iostream>
#include <vector>
#include <cstring>
#include<numeric>
#include <algorithm>
using namespace std;

#define ll long long int
vector<vector<ll>> dp;
vector<vector<ll>> a;
vector<vector<string>> path;

void reverseStr(string& str)
{
	int n = str.length();
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

int main()
{
	ll n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		vector<ll> temp;
		ll nSize;
		cin >> nSize;
		for (ll j = 0; j < nSize; j++)
		{
			ll t;
			cin >> t;
			temp.push_back(t);
		}

		a.push_back(temp);
	}

	for (ll i = 0; i <= n; i++)
	{
		vector<ll> temp;
		vector<string> temp2;

		for (ll j = 0; j <= s; j++)
		{
			temp.push_back(0);
			temp2.push_back("");
		}
		dp.push_back(temp);
		path.push_back(temp2);
	}

	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= s; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			ll statue1 = 0;
			ll statue2 = 0;
			ll statue3 = 0;
			statue1 = dp[i - 1][j];
			if (i > 0 && j >= *min_element(a[i-1].begin(), a[i-1].end())) statue2 = dp[i - 1][j - *min_element(a[i-1].begin(), a[i-1].end())] + 1;
			if (i > 0 && j >= accumulate(a[i-1].begin(), a[i-1].end(), 0)) statue3 = dp[i - 1][j - accumulate(a[i-1].begin(), a[i-1].end(), 0)] + a[i-1].size();

			if (max(max(statue1, statue2), statue3) == statue1)
			{
				path[i][j] = "0";
				dp[i][j] = statue1;
			}
			else if (max(max(statue1, statue2), statue3) == statue2)
			{
				path[i][j] = "1";
				dp[i][j] = statue2;
			}
			else if (max(max(statue1, statue2), statue3) == statue3)
			{
				path[i][j] = "2";
				dp[i][j] = statue3;
			}
		}
	}

	string aim = "";
	int i = n;
	int j = s;
	while (i != 0 && j != 0)
	{
		aim += path[i][j];
		if (path[i][j] == "0")
		{
			i--;
		}
		else if (path[i][j] == "1")
		{
			i--;
			j -= *min_element(a[i].begin(), a[i].end());
		}
		else if (path[i][j] == "2")
		{
			i--;
			j -= accumulate(a[i].begin(), a[i].end(), 0);
		}
	}
	reverseStr(aim);
	cout << dp[n][s] << "\n" << aim;
	
	for (ll i = 0; i <= n; i++)
	{
		dp[i].~vector();
	}
	dp.~vector();

	for (ll i = 0; i <= n; i++)
	{
		path[i].~vector();
	}
	path.~vector();

	for (int i = 0; i < n; i++)
	{
		a[i].~vector();
	}
	a.~vector();

	return 0;
}
