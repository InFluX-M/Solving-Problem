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

const int mxn = 200000 + 5;
const int mxLog = 25;

vi g[mxn];
int h[mxn];
vector<vi> par(mxLog, vi(mxn, -1));

void dfs(int u, int p)
{
    par[0][u] = p;
    for (int v : g[u])
    {
        if (v != p)
        {
            h[v] = h[u] + 1;
            dfs(v, u);
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;

        g[p - 1].pb(i);
        g[i].pb(p - 1);
    }

    dfs(0, -1);

    for (int k = 1; k < mxLog; k++)
        for (int i = 0; i < n; i++)
            if (par[k - 1][i] != -1)
                par[k][i] = par[k - 1][par[k - 1][i]];

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
                u = par[i][u];
            }
        }

        if (u == -1)
            cout << -1 << endl;
        else
            cout << u + 1 << endl;
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
