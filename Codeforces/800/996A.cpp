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
#define nl "\n"
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
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

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

void solve()
{
    int n;
    cin >> n;

    vector<int> p = {1, 5, 10, 20};
    int res = n / 100;

    n = n % 100;
    vi dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i - p[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - p[j]] + 1);
            }
        }
    }

    cout << dp[n] + res;
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
