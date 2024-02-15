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
const int mxlog = 20;

vector<vi> par(mxlog, vi(mxn, -1));
vi h[mxn];
int st[mxn], ft[mxn];
int timer = 0;
int ht[mxn];
vi g[mxn];

void dfs(int u, int p, int height)
{
    par[0][u] = p;
    ht[u] = height;
    h[height].pb(u);
    st[u] = timer++;

    for (int v : g[u])
    {
        if (v != p)
        {
            dfs(v, u, height + 1);
        }
    }

    ft[u] = timer;
}

int kAnc(int u, int k)
{
    for (int i = mxlog - 1; i >= 0; i--)
    {
        if ((k >> i) & 1)
        {
            u = par[i][u];
            if (u == -1)
                break;
        }
    }

    return u;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        if (p != 0)
        {
            g[p - 1].pb(i);
            g[i].pb(p - 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (par[0][i] == -1)
            dfs(i, -1, 0);
    }

    for (int k = 1; k < mxlog; k++)
        for (int i = 0; i < n; i++)
            if (par[k - 1][i] != -1)
                par[k][i] = par[k - 1][par[k - 1][i]];

    int q;
    cin >> q;

    while (q--)
    {
        int p, u;
        cin >> u >> p;
        u--;
        int heightU = ht[u];
        int g = kAnc(u, p);

        if (g == -1)
        {
            cout << 0 << ' ';
            continue;
        }

        int lo = -1, hi = h[ht[u]].size() - 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;
            int v = h[ht[u]][mid];
            if (st[v] < st[g])
                lo = mid;
            else
                hi = mid;
        }
        int L = hi;

        lo = 0, hi = h[ht[u]].size();
        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;
            int v = h[ht[u]][mid];
            if (ft[v] <= ft[g])
                lo = mid;
            else
                hi = mid;
        }
        int R = lo;
        cout << R - L << " ";
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
