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
vi g[mxn];
vi euler;
int h[mxn];
int hsh[mxn];

void dfs(int u, int p, int he)
{
    h[u] = he;
    euler.pb(u);
    hsh[u] = sz(euler) - 1;

    for (int v : g[u])
        if (v != p)
        {
            dfs(v, u, he + 1);
            euler.pb(u);
        }
}

int y = 1;

void solve()
{
    int n, q;
    cin >> n;

    /*for (int i = 0; i < n - 1; i++)
    {
        int m;
        cin >> m;
        m--;
        g[m].pb(i + 1);
        g[i + 1].pb(m);
    }*/

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++)
        {
            int u;
            cin >> u;
            g[i].pb(u - 1);
            g[u - 1].pb(i);
        }
    }

    dfs(0, -1, 0);
    n = sz(euler);

    vector<vi> rmq(ceil(log2(n)) + 1, vi(n, -1));
    vector<vi> irmq(ceil(log2(n)) + 1, vi(n, -1));

    for (int i = 0; i < n; i++)
        rmq[0][i] = h[euler[i]], irmq[0][i] = euler[i];

    for (int k = 1; k < ceil(log2(n)) + 1; k++)
        for (int i = 0; i <= n - (1 << k); i++)
        {
            int l = rmq[k - 1][i];
            int r = rmq[k - 1][i + (1 << (k - 1))];
            rmq[k][i] = min(l, r);
            irmq[k][i] = l > r ? irmq[k - 1][i + (1 << (k - 1))] : irmq[k - 1][i];
        }

    vi p(n + 1, -1);
    for (int i = 1; i < n + 1; i++)
        p[i] = log2(i);

    cin >> q;

    cout << "Case " << y++ << ":" << nl;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        u--, v--;

        if (u == v)
        {
            cout << u + 1 << nl;
            continue;
        }

        u = hsh[u];
        v = hsh[v];

        if (u < v)
            swap(u, v);

        int pi = p[u - v];

        int l = rmq[pi][v];
        int r = rmq[pi][u - (1 << pi)];
        cout << ((l > r) ? irmq[pi][u - (1 << pi)] + 1 : irmq[pi][v] + 1);

        cout << nl;
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
