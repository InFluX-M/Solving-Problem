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

int n;

void topologicalSortUtil(int v, bool visited[], stack<int> &Stack, vector<vi> &g)
{
    visited[v] = true;

    for (int u : g[v])
    {
        if (!visited[u])
            topologicalSortUtil(u, visited, Stack, g);
    }

    Stack.push(v);
}

vi topologicalSort(vector<vi> &g)
{
    stack<int> Stack;

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack, g);

    vi res;
    while (Stack.empty() == false)
    {
        res.push_back(Stack.top());
        Stack.pop();
    }

    return res;
}

void dfs(int u, vector<bool> &vis, vector<vi> &g)
{
    vis[u] = true;
    for (int v : g[u])
    {
        if (!vis[v])
            dfs(v, vis, g);
    }
}

void solve()
{
    int m;
    cin >> n;

    vector<vi> g(n, vi());
    vector<vi> g1(n, vi());

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            t--;
            g[t].push_back(i);
            g1[i].push_back(t);
        }
    }

    vector<bool> vis(n, false);
    dfs(0, vis, g1);
    unordered_set<int> pr;
    for (int i = 1; i < n; i++)
    {
        if (vis[i])
            pr.insert(i);
    }

    vi res = topologicalSort(g);
    for (int i = 0; i < sz(res); i++)
    {
        if (pr.find(res[i]) != pr.end())
            cout << res[i] + 1 << ' ';
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
