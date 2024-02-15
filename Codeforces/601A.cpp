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
int n, m;
int bfs(vector<vi> &g)
{
    vector<int> dis(n, INT_MAX);
    vector<bool> vis(n, false);

    dis[0] = 0;
    vis[0] = true;

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (g[u][i] && !vis[i])
            {
                vis[i] = true;
                dis[i] = dis[u] + 1;
                q.push(i);
            }
        }
    }

    return ((dis[n - 1] == INT_MAX) ? -1 : dis[n - 1]);
}

void solve()
{
    cin >> n >> m;

    vector<vi> g(n, vi(n, 0)), gr(n, vi(n, 1));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u][v] = 1;
        g[v][u] = 1;

        gr[u][v] = 0;
        gr[v][u] = 0;
    }

    int l1 = bfs(g);
    int l2 = bfs(gr);

    if (l1 < 0 || l2 < 0)
        cout << -1;
    else
        cout << max(l1, l2);
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
