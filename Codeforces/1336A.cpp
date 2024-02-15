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
bool compareInterval(tuple<int, int, int> i1, tuple<int, int, int> i2)
{
    if (get<1>(i1) == get<1>(i2))
        return get<0>(i2) < get<0>(i1);
    return get<1>(i1) < get<1>(i2);
}

int dfs(int u, int parent, vector<vi> &adj, vector<int> &dp)
{
    for (int v : adj[u])
    {
        if (v != parent)
        {
            dp[u] += (dfs(v, u, adj, dp) + 1);
        }
    }
    return dp[u];
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<vi> adj(n, vi());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(0);
    vector<int> dep(n, 0);
    vector<int> vis(n, false);

    while (!q.empty())
    {
        int u = q.front();
        vis[u] = true;
        q.pop();

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                q.push(v);
                dep[v] = dep[u] + 1;
            }
        }
    }

    if (n == k)
        cout << 0;
    else
    {
        vector<int> dp(n, 0);
        dfs(0, 0, adj, dp);
        for (int i = 0; i < n; i++)
        {
            dp[i] -= dep[i];
        }

        sort(all(dp), greater<int>());
        ll res = 0;
        for (int i = 0; i < n - k; i++)
        {
            res += dp[i];
        }
        cout << res;
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
