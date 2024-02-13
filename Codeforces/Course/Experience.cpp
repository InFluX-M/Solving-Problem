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

const int mxn = 2e5 + 5;

int par[mxn];
vi team[mxn];
int h[mxn];
ll val[mxn];
ll del[mxn];

int find(int u)
{
    return par[u] == -1 ? u : par[u] = find(par[u]);
}

void merge(int u, int v)
{
    if ((u = find(u)) == (v = find(v)))
        return;

    if (h[u] < h[v])
        swap(u, v);

    for (int x : team[v])
        team[u].pb(v), del[x] += val[v] - val[u];

    par[v] = u;
    val[v] = 0;

    team[v].clear();

    h[u] += (h[u] == h[v]);
}
void solve()
{
    int n, m;
    cin >> n >> m;

    memset(par, -1, sizeof(par));

    for (int i = 1; i <= n; i++)
        team[i].pb(i);

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        int u, v;

        if (s == "add")
        {
            cin >> u >> v;
            val[find(u)] += v;
        }
        else if (s == "join")
        {
            cin >> u >> v;
            merge(u, v);
        }
        else
        {
            cin >> u;
            cout << del[u] + val[find(u)] << nl;
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
