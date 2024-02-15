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

vi bfs(int s, int n, vector<vi> &adj)
{
    queue<int> q;
    vi dis(n, INT_MAX);
    vector<bool> vis(n, false);

    q.push(s);
    dis[s] = 0;
    vis[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    return dis;
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

    int s1, t1, l1;
    cin >> s1 >> t1 >> l1;
    int s2, t2, l2;
    cin >> s2 >> t2 >> l2;

    s1--, t1--, s2--, t2--;

    vector<vi> shortestPath(n, vi(n, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        vi res = bfs(i, n, adj);
        for (int j = 0; j < n; j++)
        {
            shortestPath[i][j] = min(res[j], shortestPath[i][j]);
            shortestPath[j][i] = min(res[j], shortestPath[j][i]);
        }
    }

    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int r1 = shortestPath[s1][i] + shortestPath[i][j] + shortestPath[j][t1];
            int r2 = shortestPath[s2][i] + shortestPath[i][j] + shortestPath[j][t2];
            int r3 = shortestPath[s2][i] + shortestPath[i][j] + shortestPath[j][t2];

            if(r1 <= l)
            mn = min(mn, shortestPath[s1][i] + shortestPath[i][j] + shortestPath[j][t1]);
        }
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
