#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;

#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define F first
#define S second

ll modOp(ll a, ll b, int op)
{
	switch (op)
	{
	case 0:
		return ((a % MOD) + (b % MOD)) % MOD;
	case 1:
		return ((a % MOD) - (b % MOD) + MOD) % MOD;
	case 2:
		return (a % MOD) * (b % MOD) % MOD;
	}
}

int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	vi a(n);
	vl ps(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ps[i] = (i == 0) ? a[i] : a[i] + ps[i - 1];
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		cout << (l == 0) ? ps[r] : ps[r] - ps[l - 1] << '\n';
	}

	return 0;
}
