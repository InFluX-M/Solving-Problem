#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long long ull;
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

const ll INF = 2e18;

ll mult(ll a, ll b)
{
    if (!b)
        return 0;
    if (a > INF / b)
        return INF;

    return a * b;
}

ll _pow(ll a, int p)
{
    if (!p)
        return 1;
    return mult(_pow(mult(a, a), p / 2), (p & 1 ? a : 1));
}

void solve()
{
    int n;
    cin >> n;

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<vl> dp(n + 1, vl(10, 1e18 + 1));

    for (int j = 0; j < 10; j++)
    {
        dp[1][j] = 1;
        for (int i = 2; i <= n; i++)
            dp[i][j] = INF;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            int p = primes[j - 1];
            for (int t = 0; t <= i; t++)
            {
                if (i % (t + 1) == 0)
                {
                    ll v = mult(dp[i / (t + 1)][j - 1], _pow(p, t));
                    if (v < dp[i][j])
                        dp[i][j] = v;
                }
            }
        }
    }

    ll res = 1e18 + 1;
    for (int j = 1; j < 10; j++)
    {
        res = min(res, dp[n][j]);
    }

    cout << res;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
