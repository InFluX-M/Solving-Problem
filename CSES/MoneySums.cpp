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

    vector<vector<bool>> dp(n + 1, vector<bool>(1e5 + 1, false));

    dp[0][0] = true;
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1e5; j++)
        {
            bool tmp = false;
            if (j - s[i - 1] >= 0)
                tmp = dp[i - 1][j - s[i - 1]];
            dp[i][j] = dp[i - 1][j] | tmp;

            if (i == n && dp[i][j])
                cnt++;
        }
    }

    cout << cnt - 1 << nl;
    for (int j = 1; j <= 1e5; j++)
    {
        if (dp[n][j])
            cout << j << ' ';
    }
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
