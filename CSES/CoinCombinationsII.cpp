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

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

void solve()
{
    int N, W;
    cin >> N >> W;

    vector<int> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }

    vector<vi> dp(N + 1, vi(W + 1, 0));

    dp[0][0]  = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - s[i - 1] >= 0)
            {
                dp[i][j] = (dp[i][j] + dp[i][j - s[i - 1]]) % MOD;
            }
        }
    }

    cout << dp[N][W];
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
