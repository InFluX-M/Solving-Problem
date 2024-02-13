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
const int mxn = 1e5 + 1;
const int mxLog = 20;
int mxh = 0;

vi g[mxn];
int st[mxn];
int ft[mxn];
int ht[mxn];
int timer = 0;
vector<vi> par(mxLog, vi(mxn, -1));
vector<vector<vi>> mins(mxLog, vector<vi>());
vi val(mxn);

void dfs(int u, int p, int h)
{
    st[u] = timer++;
    ht[u] = h;
    par[0][u] = p;
    mins[0][u].pb(val[p]);

    mxh = max(mxh, h);

    for (int v : g[u])
    {
        if (v != p)
        {
            dfs(v, u, h + 1);
        }
    }

    ft[u] = timer;
}

bool isAnc(int u, int v)
{
    return st[u] <= st[v] && ft[u] >= ft[v];
}

int lca(int u, int v)
{
    for (int i = mxLog - 1; i >= 0; i--)
    {
        int t = par[i][u];
        if (t == -1 || isAnc(t, v) || t == v)
            continue;

        u = t;
    }

    return par[0][u];
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1, 0);

    for(int i = 0 ; i < m; i++) val[]

    for (int i = 1; i <= log2(mxh); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
                par[i][j] = -1;
            else
            {
                par[i][j] = par[i - 1][par[i - 1][j]];

               
            }
        }
    }

    while (q--)
    {
        int u, v, a;
        cin >> u >> v >> a;

        u--, v--;

        int LCA = lca(u, v);

        vi l;
        for (int i = mxLog - 1; i >= 0; i--)
        {
            int t = par[i][u];
            if (t == -1 || isAnc(t, LCA) || t == LCA)
                continue;

            for (int tmp : mins[i][u])
                l.pb(tmp);
        }

        for (int i = mxLog - 1; i >= 0; i--)
        {
            int t = par[i][v];
            if (t == -1 || isAnc(t, LCA) || t == LCA)
                continue;

            for (int tmp : mins[i][v])
                l.pb(tmp);
        }

        sort(all(l));
        int k = min(sz(l), a);
        cout << k << endl;
        for (int i = 0; i < k; i++)
            cout << l[i] << ' ';

        cout << endl;
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
