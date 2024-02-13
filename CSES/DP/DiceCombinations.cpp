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
const int mx = 1e6 + 1;

void solve()
{
    int n;
    cin >> n;

    vl dp(mx, 0);

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 8;
    dp[4] = 16;
    dp[5] = 32;

    for (int i = 6; i < mx; i++)
        for (int j = 1; j <= 6; j++)
            dp[i] = modOp(dp[i], dp[i - j], 0);

    cout << dp[n - 1] % MOD;
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
