#include <iostream>
using namespace std;

//مستطیل بد پیشرفته

#define ll long long int
ll mod = (ll)(1e9 + 7);

ll mul(ll a, ll b) {
	return (a % mod) * (b % mod) % mod;
}
ll min(ll a, ll b) {
	return ((a % mod) - (b % mod) + mod) % mod;
}

int main()
{
	ll n;
	cin >> n;

	ll bound = (n / 2 + 1) / 2;
	ll answer = min(mul(bound, bound + 1), mul(n / 2, bound)) + n / 3 - bound;
	ll k = (n / 3) / 2;
	answer += min(mul(n + 1, k), 3 * mul(k, k + 1));

	if ((n / 3) % 2 == 1)
		answer += (n - 3 * (2 * k + 1)) / 2;

	cout << answer % mod;

}