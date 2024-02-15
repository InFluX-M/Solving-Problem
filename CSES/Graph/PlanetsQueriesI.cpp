#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
using pqg = priority_queue<T>;
template <class T>
using pql = priority_queue<T, vector<T>, greater<T>>;

const ll inf = 1e18;
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
#define lb lower_bound
#define ub upper_bound
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

const int mxn = 2e5 + 4;
const int mxLog = 32;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<vi> dp(mxLog, vi(n, -1));

    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        u--;
        dp[0][i] = u;
    }

    for (int i = 1; i < mxLog; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];

    while (q--)
    {
        int u, k;
        cin >> u >> k;
        u--;

        for (int i = mxLog - 1; i >= 0; i--)
        {
            if (u == -1)
                break;
            if ((k >> i) & 1)
            {
                u = dp[i][u];
            }
        }

        cout << u + 1 << '\n';
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
