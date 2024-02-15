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

vector<vi> comp;
void dfs(int u, vector<vi> &adj, vector<bool> &vis, vector<int> &c)
{
    vis[u] = true;
    c.push_back(u);

    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v, adj, vis, c);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n, vi());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vector<int> c;
            dfs(i, adj, vis, c);
            comp.push_back(c);
        }
    }

    int res = 0;
    for (vi v : comp)
    {
        bool flag = true;
        for (int u : v)
        {
            if (adj[u].size() != 2)
            {
                flag = false;
                break;
            }
        }
        res += flag;
    }

    cout << res;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
