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

    vector<str> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vi> dp(n, vi(m, 0));
    int r = 1;
    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == '#')
            r = 0;
        dp[0][i] = r;
    }

    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == '#')
            c = 0;
        dp[i][0] = c;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = modOp(dp[i - 1][j], dp[i][j - 1], 0);
            if (grid[i][j] == '#')
                dp[i][j] = 0;
        }
    }

    cout << dp[n - 1][m - 1];
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
