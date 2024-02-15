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
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
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

#define inf ll(1e17)

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> g(2 * n, vector<pii>());
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--, v--;

        g[u].pb({v, w});
        g[v + n].push_back({u + n, w});
    }

    for (int i = 0; i < n; i++)
    {
        g[i].push_back({i + n, 0});
    }

    vector<ll> dis(2 * n, inf);
    vector<bool> vis(2 * n, false);

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dis[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pll u = pq.top();
        pq.pop();

        if (vis[u.second])
            continue;
        vis[u.second] = true;

        for (pll v : g[u.S])
        {
            if (dis[v.first] > dis[u.second] + v.second)
            {
                dis[v.first] = dis[u.second] + v.second;
                pq.push({dis[v.first], v.first});
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << ((dis[i + n] == inf) ? -1 : dis[i + n]) << ' ';
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
