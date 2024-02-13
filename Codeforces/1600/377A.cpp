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

int idx(int i, int j, int m)
{
    return i * (m + 2) + j;
}

int n, m, s, em = 0, res = 0;
bool ret = false;
void dfs(int u, vector<unordered_set<int>> &adj, vector<bool> &vis)
{
    vis[u] = true;
    res++;

    for (int v : adj[u])
    {
        if (!vis[v] && res < em - s)
            dfs(v, adj, vis);
    }
}

void solve()
{
    cin >> n >> m >> s;
    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '#'));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '.')
                em++;
        }
    }

    vector<unordered_set<int>> adj((n + 2) * (m + 2), unordered_set<int>());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '#')
                continue;

            if (grid[i - 1][j] == '.')
            {
                adj[i * (m + 2) + j].insert((i - 1) * (m + 2) + j);
            }
            if (grid[i + 1][j] == '.')
            {
                adj[i * (m + 2) + j].insert((i + 1) * (m + 2) + j);
            }
            if (grid[i][j - 1] == '.')
            {
                adj[i * (m + 2) + j].insert((i) * (m + 2) + j - 1);
            }
            if (grid[i][j + 1] == '.')
            {
                adj[i * (m + 2) + j].insert((i) * (m + 2) + j + 1);
            }
        }
    }

    int iA = 1, jA = 1;
    bool h = false;
    for (int l = 1; l <= n; l++)
    {
        for (int r = 1; r <= m; r++)
            if (grid[l][r] == '.')
            {
                iA = l, jA = r;
                h = true;
                break;
            }

        if (h)
            break;
    }
    vector<bool> vis((n + 2) * (m + 2), false);
    dfs(idx(iA, jA, m), adj, vis);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '#')
                cout << '#';
            else
            {
                cout << ((vis[idx(i, j, m)]) ? '.' : 'X');
            }
        }
        cout << nl;
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
