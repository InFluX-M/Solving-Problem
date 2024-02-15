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

#define inf ll(1e18)

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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> g(n, vector<pii>());
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<ll> dis(n, inf);
    vector<ll> path(n, -1);
    vector<bool> vis(n, false);

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dis[0] = 0;
    vis[0] = true;
    path[0] = -1;

    pq.push(mp(0, 0));

    for (int i = 0; i < n - 1; i++)
    {
        int idx = pq.top().second;
        pq.pop();

        vis[idx] = true;
        for (pii v : g[idx])
        {
            if (dis[v.first] > dis[idx] + v.second)
            {
                path[v.first] = idx;
                dis[v.first] = dis[idx] + v.second;
                pq.push(mp(dis[v.first], v.first));
            }
        }
    }

    if (dis[n - 1] == inf)
    {
        cout << -1;
        return;
    }

    stack<int> res;
    res.push(n - 1);

    int u = n - 1;
    while (u != -1)
    {
        res.push(path[u]);
        u = path[u];
    }

    res.pop();
    while (!res.empty())
    {
        cout << res.top() + 1 << ' ';
        res.pop();
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
