#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll mod = 1e9 + 7;

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2")

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

ll mul(ll a, ll b)
{
    return (a % mod) * (b % mod) % mod;
}

ll min(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll sum(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;

        int a[2][m];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        int dp[2][m];
        dp[0][0] = a[0][0];
        dp[1][0] = a[1][0];
        for (int j = 1; j < m; j++)
        {
            dp[0][j] = dp[0][j - 1] + a[0][j];
            dp[1][j] = dp[1][j - 1] + a[1][j];
        }

        ll ans = dp[0][m - 1] - dp[0][0];
        ll ansId = 0;

        for (int i = 1; i < m; i++)
        {
            ll cur1 = dp[0][m - 1] - dp[0][i];
            ll cur2 = dp[1][i - 1];

            ll mx = max(cur1, cur2);
            if (mx < ans)
            {
                ans = mx;
                ansId = i;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
