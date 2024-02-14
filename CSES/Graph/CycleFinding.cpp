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

const int mxn = 2500;
bool vis[mxn];
vector<pii> g[mxn];
vector<int> gu[mxn];
vector<vi> comps;
vi comp;

void dfs(int u)
{
    vis[u] = true;
    comp.pb(u);
    for (int v : gu[u])
    {
        if (!vis[v])
            dfs(v);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> s;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({v, w});
        gu[u].pb(v);
        gu[v].pb(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            comps.pb(comp);
            comp.clear();
        }
    }

    for (int i = 0; i < sz(comps); i++)
    {
        map<int, ll> dist;
        for (int u : comps[i])
            dist[u] = 1e18;

        map<int, int> ps;
        for (int u : comps[i])
            ps[u] = -1;

        dist[comps[i][0]] = 0;
        for (int j = 1; j < sz(comps[i]); j++)
        {
            for (int u : comps[i])
            {
                for (pii v : g[u])
                {
                    if (dist[u] != 1e18 && dist[u] + v.S < dist[v.F])
                    {
                        dist[v.F] = dist[u] + v.S;
                        ps[v.F] = u;
                    }
                }
            }
        }

        int x = -1;

        for (int u : comps[i])
        {
            for (pii v : g[u])
            {
                if (dist[u] != 1e18 && dist[u] + v.S < dist[v.F])
                {
                    dist[v.F] = dist[u] + v.S;
                    ps[v.F] = u;
                    x = v.F;
                }
            }
        }

        if (x == -1)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < sz(comps[i]); ++j)
                x = ps[x];

            vector<int> cycle;
            for (int v = x;; v = ps[v])
            {
                cycle.push_back(v);
                if (v == x && cycle.size() > 1)
                    break;
            }
            reverse(cycle.begin(), cycle.end());
            cout << "YES\n";

            for (int t : cycle)
                cout << t + 1 << ' ';

            return;
        }
    }

    cout << "NO";
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
