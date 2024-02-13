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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pii> g[n], gr[n];
    vector<tuple<int, int, int>> s(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({v, w});
        gr[v].pb({u, w});
        s[i] = make_tuple(u, v, w);
    }

    vector<bool> vis(n, false);
    vl dis(n, 1e18);

    dis[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pll u = pq.top();
        pq.pop();

        ll idx = u.second;
        ll dist = u.first;

        if (vis[u.second])
            continue;

        vis[idx] = true;

        for (pll v : g[idx])
        {
            if (v.S + dis[idx] < dis[v.F])
            {
                dis[v.F] = v.S + dis[idx];
                pq.push({dis[v.F], v.first});
            }
        }
    }

    fill_n(vis.begin(), n, false);
    vl dis1(n, 1e18);
    dis1[n - 1] = 0;
    pq.push({0, n - 1});

    while (!pq.empty())
    {
        pll u = pq.top();
        pq.pop();
        
        ll idx = u.second;
        ll dist = u.first;

        if (vis[u.second])
            continue;

        vis[idx] = true;

        for (pii v : gr[idx])
        {
            if (v.S + dis1[idx] < dis1[v.F])
            {
                dis1[v.F] = v.S + dis1[idx];
                pq.push({dis1[v.F], v.F});
            }
        }
    }

    ll ans = 1e18;
    for (int i = 0; i < m; i++)
    {
        ans = min(ans, dis[get<0>(s[i])] + get<2>(s[i]) / 2 + dis1[get<1>(s[i])]);
    }

    cout << ans;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
