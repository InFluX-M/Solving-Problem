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

int n;
vector<int> g[mxn];
vector<bool> visited(mxn, false);
vector<int> parent(mxn, -1);
int cycle_start = -1, cycle_end = -1;

bool dfs(int u, int par)
{
    visited[u] = true;
    for (int v : g[u])
    {
        if (v == par)
            continue;
        if (visited[v])
        {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        parent[v] = u;
        if (dfs(v, parent[v]))
            return true;
    }
    return false;
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

    visited.assign(n, false);
    parent.assign(n, -1);

    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        cout << sz(cycle) << '\n';
        for (int v : cycle)
            cout << v + 1 << " ";
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
