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
    int n, m;
    cin >> n >> m;

    vl s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<vl> dp(n, vl(m + 2, 0));

    if (s[0] != 0)
        dp[0][s[0]] = 1;
    else
        for (int j = 1; j <= m; j++)
            dp[0][j] = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] != 0)
        {
            dp[i][s[i]] = dp[i - 1][s[i] - 1] + dp[i - 1][s[i]] + dp[i - 1][s[i] + 1];
            dp[i][s[i]] %= MOD;
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
    }

    ll res = 0;
    for (int j = 1; j <= m; j++)
    {
        res += dp[n - 1][j];
        res %= MOD;
    }

    cout << res;
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
