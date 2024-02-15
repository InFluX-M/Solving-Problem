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

vector<pair<vector<int>, vector<int>>> adj;
vector<bool> reStack;
vector<bool> visited;

bool dfs(int u)
{
    visited[u] = true;
    reStack[u] = true;

    for (int v : adj[u].first)
    {
        if (!visited[v] && dfs(v))
        {
            return true;
        }
        else if (reStack[v])
        {
            return true;
        }
    }

    reStack[u] = false;
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        adj.push_back(mp(vi(), vector<int>(26, 0)));
        reStack.push_back(false);
        visited.push_back(false);
    }

    vector<int> D(n, 0);
    string s;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].first.push_back(v);
        D[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (D[i] == 0)
        {
            adj[i].second[s[i]]++;
            q.push(i);
        }
    }

    int res = 0;
    while (!q.empty())
    {
        int u = q.front();

        for (int v : adj[u].first)
        {
            for (int k = 0; k < 26; k++)
            {
                if ('a' + k == s[v])
                    adj[v].second[k] = max(adj[v].second[k], adj[u].second[k] + 1);
                else
                    adj[v].second[k] = max(adj[v].second[k], adj[u].second[k]);

                
            }
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
