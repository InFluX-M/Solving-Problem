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
vector<pii> g[mxn];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({v, w});
    }

    vl routes(n, 0);
    vl min_flight(n, 0);
    vl max_flight(n, 0);
    vl dist(n, 1e18);
    vector<bool> vis(n, false);
    pqg<pll> pqM;

    dist[0] = 0;
    min_flight[0] = 0;
    max_flight[0] = 0;
    routes[0] = 1;
    pqM.push({0, 0});

    while (pqM.size())
    {
        pll p = pqM.top();
        pqM.pop();
        int u = p.S;
        if (vis[u])
            continue;
        vis[u] = true;
        for (pii &v : g[u])
        {
            if (dist[v.F] > dist[u] + v.S)
            {
                dist[v.F] = dist[u] + v.S;
                min_flight[v.F] = min_flight[u] + 1;
                max_flight[v.F] = max_flight[u] + 1;
                routes[v.F] = routes[u];
                pqM.push({dist[v.F], v.F});
            }
            else if (dist[v.F] == dist[u] + v.S)
            {
                min_flight[v.F] = min(min_flight[v.F], min_flight[u] + 1);
                max_flight[v.F] = max(max_flight[v.F], max_flight[u] + 1);
                routes[v.F] = modOp(routes[v.F], routes[u], 0);
                pqM.push({dist[v.F], v.F});
            }
        }
    }

    cout << dist[n - 1] << " " << routes[n - 1] << " " << min_flight[n - 1] << " " << max_flight[n - 1] << nl;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
