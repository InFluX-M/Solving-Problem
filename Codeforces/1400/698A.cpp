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

    vi s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<ll>> dp(3, vl(n, INT_MAX));
    if (s[0] == 0)
    {
        dp[0][0] = 1;
        dp[1][0] = INT_MAX;
        dp[2][0] = INT_MAX;
    }
    else if (s[0] == 1)
    {
        dp[0][0] = 1;
        dp[1][0] = 0;
        dp[2][0] = INT_MAX;
    }
    else if (s[0] == 2)
    {
        dp[0][0] = 1;
        dp[1][0] = INT_MAX;
        dp[2][0] = 0;
    }
    else
    {
        dp[0][0] = 1;
        dp[1][0] = 0;
        dp[2][0] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] == 0)
        {
            dp[0][i] = min(dp[1][i - 1], min(dp[0][i - 1], dp[2][i - 1])) + 1;
            dp[1][i] = INT_MAX;
            dp[2][i] = INT_MAX;
        }
        else if (s[i] == 1)
        {
            dp[0][i] = min(dp[1][i - 1], min(dp[0][i - 1], dp[2][i - 1])) + 1;
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
            dp[2][i] = INT_MAX;
        }
        else if (s[i] == 2)
        {
            dp[0][i] = min(dp[1][i - 1], min(dp[0][i - 1], dp[2][i - 1])) + 1;
            dp[1][i] = INT_MAX;
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
        }
        else
        {
            dp[0][i] = min(dp[1][i - 1], min(dp[0][i - 1], dp[2][i - 1])) + 1;
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
        }
    }

    cout << min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1]));
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
