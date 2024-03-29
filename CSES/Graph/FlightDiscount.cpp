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
using pql = priority_queue<T>;
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

const int mxn = 1e5;

vector<pair<int, int>> g[mxn], gT[mxn];
ll dis[mxn];
ll disT[mxn];
bool vis[mxn];
bool visT[mxn];
pqg<pair<ll, int>> pq;
vector<tuple<int, int, int>> edges;

void solve()
{
    int n, m;
    cin >> n >> m;

    fill_n(dis, n, 1e18);
    fill_n(disT, n, 1e18);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({v, w});
        gT[v].pb({u, w});
        edges.pb(make_tuple(u, v, w));
    }

    dis[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pair<ll, int> u = pq.top();
        pq.pop();

        if (vis[u.S])
            continue;

        vis[u.S] = true;

        for (pii v : g[u.S])
        {
            if (dis[v.F] > dis[u.S] + v.S)
            {
                dis[v.F] = dis[u.S] + v.S;
                pq.push({dis[v.F], v.F});
            }
        }
    }

    disT[n - 1] = 0;
    pq.push({0, n - 1});

    while (!pq.empty())
    {
        pair<ll, int> u = pq.top();
        pq.pop();

        if (visT[u.S])
            continue;

        visT[u.S] = true;

        for (pii v : gT[u.S])
        {
            if (disT[v.F] > disT[u.S] + v.S)
            {
                disT[v.F] = disT[u.S] + v.S;
                pq.push({disT[v.F], v.F});
            }
        }
    }

    ll aim = 1e18;

    for (int u = 0; u < n; u++)
        for (pii v : g[u])
            aim = min(aim, dis[u] + disT[v.F] + v.S / 2);

    cout << aim;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
