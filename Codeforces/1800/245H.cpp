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
    string s;
    cin >> s;

    int n = sz(s);
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = true;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            dp[1][i] = true;
    }

    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (s[j] == s[j + i] && dp[i - 2][j + 1])
                dp[i][j] = true;
        }
    }

    vector<vi> c(n, vi(n, 0));
    for (int i = 0; i < n; i++)
        c[0][i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = c[i - 1][j] + (dp[i][j]);
        }
    }

    vector<vi> res(n, vi(n, 0));
    for (int i = 0; i < n; i++)
    {
        res[0][i] = c[0][i];
        for (int j = i - 1; j >= 0; j--)
        {
            res[i - j][j] = res[i - j - 1][j + 1] + c[i - j][j];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << res[r - l][l - 1] << nl;
    }
}

int32_t main()
{
    fastio;
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
