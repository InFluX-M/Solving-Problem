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
int idx(int i, int j)
{
    return i * m + j;
}

void dfs(int u, vector<vi> &adj, vector<bool> &vis)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v, adj, vis);
    }
}

void solve()
{
    cin >> n >> m;

    n++, m++;
    n++, m++;
    vector<vi> adj(n * m, vi());
    vector<vector<char>> g(n, vector<char>(m, '#'));

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (g[i][j] == '#')
                continue;
            if (g[i - 1][j] == '.')
            {
                adj[idx(i, j)].push_back(idx(i - 1, j));
            }
            if (g[i][j - 1] == '.')
            {
                adj[idx(i, j)].push_back(idx(i, j - 1));
            }
            if (g[i][j + 1] == '.')
            {
                adj[idx(i, j)].push_back(idx(i, j + 1));
            }
            if (g[i + 1][j] == '.')
            {
                adj[idx(i, j)].push_back(idx(i + 1, j));
            }
        }
    }
    vector<bool> vis(n * m, false);
    int nC = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (!vis[idx(i, j)] && g[i][j] == '.')
            {
                nC++;
                dfs(idx(i, j), adj, vis);
            }
        }
    }

    cout << nC;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
