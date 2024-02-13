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

const int mxn = 1e5;
vector<int> g[mxn];
vector<int> p(mxn, -1);
vector<bool> vis(mxn, false);
bool cycle = false;
int x, y;

void dfs(int u)
{
    vis[u] = true;

    for (int v : g[u])
    {
        if (!vis[v])
        {
            p[v] = u;
            dfs(v);
        }
        else if (v != p[u])
        {
            cycle = true;
            x = v;
            y = u;
            return;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            p[i] = -1;
            dfs(i);
        }
        if (cycle)
        {
            int z;

            vector<bool> lca(n, false);
            vi r;
            int u = x;
            while (u != -1)
            {
                lca[u] = true;
                u = p[u];
            }

            u = y;
            while (u != -1)
            {
                if (lca[u])
                {
                    z = u;
                    break;
                }
                lca[u] = true;
                u = p[u];
            }

            u = x;
            while (u != z)
            {
                r.pb(u);
                u = p[u];
            }

            r.pb(z);
            stack<int> s;
            u = y;
            while (u != z)
            {
                s.push(u);
                u = p[u];
            }

            while (!s.empty())
            {
                r.push_back(s.top());
                s.pop();
            }

            r.pb(x);

            cout << sz(r) << nl;
            for (int m : r)
            {
                cout << m + 1 << ' ';
            }

            return;
        }
    }

    cout << "IMPOSSIBLE";
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
