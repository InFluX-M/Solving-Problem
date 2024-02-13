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
    int a, b;
    cin >> a >> b;

    vector<vi> dp(a + 1, vi(b + 1, INT_MAX));
    dp[0][0] = 1;
    for (int k = 0; k <= a; k++)
        dp[k][0] = 0;

    for (int k = 0; k <= b; k++)
        dp[0][k] = 0;

    dp[0][0] = 0;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                int aim = INT_MAX;
                for (int k = 1; k < i; k++)
                {
                    aim = min(dp[k][j] + dp[i - k][j] + 1, aim);
                }
                for (int k = 1; k < j; k++)
                {
                    aim = min(dp[i][k] + dp[i][j - k] + 1, aim);
                }

                dp[i][j] = aim;
            }
        }
    }
    cout << dp[a][b];
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
