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
        cin >> s[i];

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        vector<int> divisor;
        for (int k = 1; k * k <= s[i - 1]; k++)
        {
            if (s[i - 1] % k == 0)
            {
                divisor.push_back(k);
                if (k != s[i - 1] / k && s[i - 1] % (s[i - 1] / k) == 0)
                    divisor.push_back(s[i - 1] / k);
            }
        }
        divisor.push_back(0);
        sort(all(divisor), greater<ll>());

        for (int j = 0; j < sz(divisor) - 1; j++)
        {
            if (divisor[j] > n || divisor[j] == 0)
                continue;
            dp[divisor[j]] += dp[divisor[j] - 1];
            dp[divisor[j]] %= MOD;
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += dp[i];
    }
    cout << res % MOD;
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
