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

int res = 0;
int m;

void dfs(int u, int parent, int k, vector<vi> &adj, vi &d)
{
    if (adj[u].size() == 1 && k + d[u] <= m && adj[u][0] == parent)
    {
        res++;
    }
    for (int v : adj[u])
    {
        if (v != parent)
        {
            if (d[u])
                if (k + 1 <= m)
                    dfs(v, u, k + 1, adj, d);
                else
                    continue;
            else
                dfs(v, u, 0, adj, d);
        }
    }
}

void solve()
{
    int n;
    cin >> n >> m;

    vector<vi> adj(n, vi());
    vi d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int> cnt(n, 0);
    dfs(0, 0, 0, adj, d);

    cout << res;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
