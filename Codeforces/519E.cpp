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
vi val(mxn);
int szSubTree[mxn];
int L, R;

void dfs(int u, int p, int h)
{
    st[u] = timer++;
    ht[u] = h;
    par[0][u] = p;
    szSubTree[u] = 1;

    mxh = max(mxh, h);

    for (int v : g[u])
    {
        if (v != p)
        {
            dfs(v, u, h + 1);
            szSubTree[u] += szSubTree[v];
        }
    }

    ft[u] = timer;
}

int kAnc(int v, int k)
{
    for (int i = mxLog - 1; i >= 0; i--)
        if (par[i][v] != -1 and ht[par[i][v]] >= k)
            v = par[i][v];
    return v;
}

bool isAnc(int u, int v)
{
    return st[u] <= st[v] && ft[u] >= ft[v];
}

int lca(int u, int v)
{
    if (ht[u] < ht[v])
        swap(u, v);

    int x = ht[u] - ht[v];
    for (int i = mxLog - 1; i >= 0; i--)
    {
        if (par[i][u] != -1 && ht[par[i][u]] >= ht[v])
            u = par[i][u];
    }

    if (u == v)
        return v;

    for (int i = mxLog - 1; i >= 0; i--)
        if (par[i][u] != -1 and par[i][v] != par[i][u])
            v = par[i][v], u = par[i][u];

    L = u, R = v;

    return par[0][u];
}

int dist(int u, int v)
{
    return ht[u] + ht[v] - 2 * ht[lca(u, v)];
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1, 0);

    for (int k = 1; k < 20; k++)
        for (int i = 0; i < n; i++)
            if (par[k - 1][i] != -1)
                par[k][i] = par[k - 1][par[k - 1][i]];

    int q;
    cin >> q;

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (u == v)
        {
            cout << n;
            continue;
        }

        int LCA = lca(u, v);
        int DIS = dist(u, v);
        if (DIS % 2)
            cout << 0 << nl;
        else
        {
            if (ht[u] > ht[v])
                swap(v, u);

            int MID = kAnc(v, ht[v] - DIS / 2);
            int MID_b = kAnc(v, ht[MID] + 1);

            if (MID == LCA)
                cout << n - szSubTree[L] - szSubTree[R] << '\n';

            else
                cout << szSubTree[MID] - szSubTree[MID_b] << '\n';
        }
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
