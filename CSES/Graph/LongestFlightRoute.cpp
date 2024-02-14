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
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

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

const int mxn = 1e5 + 4;
vector<int> g[mxn];
vector<int> visited(mxn, 0);
vector<int> res;

bool topologicalSort(int u)
{
    visited[u] = 1;
    for (int v : g[u])
    {
        if (visited[v] == 0 && topologicalSort(v))
            return true;
    }
    visited[u] = 2;
    res.pb(u);
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
    }

    topologicalSort(0);

    reverse(all(res));

    vl dist(n, -1e18);
    vi par(n, -1);

    dist[0] = 0;
    for (int u : res)
    {
        for (int v : g[u])
        {
            if (dist[v] < dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }
    }

    if (dist[n - 1] < 0)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dist[n - 1] + 1 << '\n';
        vi path;
        for (int u = n - 1; u != -1; u = par[u])
            path.pb(u);

        reverse(all(path));
        for (int i = 0; i < sz(path); i++)
            cout << path[i] + 1 << ' ';
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
