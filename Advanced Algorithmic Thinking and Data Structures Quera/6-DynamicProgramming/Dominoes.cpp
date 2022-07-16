#include <iostream>
using namespace std;

#define ll long long int
ll* dp = new ll[100000000];

int main()
{
	ll n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] % (1000000000 + 7) + dp[i - 2] % (1000000000 + 7);
	}
	
	cout << dp[n] % (1000000000 + 7);


}
