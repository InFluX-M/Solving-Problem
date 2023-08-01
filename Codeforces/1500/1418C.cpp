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
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    if (n <= 2)
    {
        cout << s[0] << nl;
    }
    else
    {
        vector<vector<ll>> dp(n, vector<ll>(2, INT_MAX));
        dp[0][0] = s[0];
        dp[0][1] = INT_MAX;

        dp[1][1] = s[0];
        dp[1][0] = s[0] + s[1];

        for (int i = 2; i < n; i++)
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + s[i]);
            dp[i][0] = min(dp[i][0], dp[i - 2][1] + s[i] + s[i - 1]);

            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
            dp[i][1] = min(dp[i][1], dp[i - 2][0]);
        }

        cout << min(dp[n - 1][0], dp[n - 1][1]) << nl;
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
