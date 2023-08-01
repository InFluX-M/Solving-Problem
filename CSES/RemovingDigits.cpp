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

    vector<ll> dp(1e6 + 2, INT_MAX);
    for (int i = 1; i < 10; i++)
        dp[i] = 1;

    for (int i = 10; i <= 1e6 + 1; i++)
    {
        int temp = i;
        for (int j = 0; j < 7 && i / 10 >= 0; j++)
        {
            dp[i] = min(dp[i], dp[i - temp % 10] + 1);
            if (temp == 0)
                break;
            temp /= 10;
        }
    }

    cout << dp[n];
}

int32_t main()
{
    int t = 1;
    while (t--)
        solve();

    return 0;
}
