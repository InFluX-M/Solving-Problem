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

const int mxn = 3e5 + 4;
int par[mxn];
int sze[mxn];
int mx[mxn];
int mn[mxn];

int find(int u)
{
    return par[u] == -1 ? u : par[u] = find(par[u]);
}

void merge(int u, int v)
{
    if ((u = find(u)) == (v = find(v)))
        return;

    if (sze[u] < sze[v])
        swap(u, v);

    mx[u] = max(mx[u], mx[v]);
    mn[u] = min(mn[u], mn[v]);

    par[v] = u;
    sze[u] += sze[v];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    memset(par, -1, sizeof(par));
    for (int i = 0; i < n; i++)
    {
        sze[i] = 1;
        mn[i] = i;
        mx[i] = i;
    }

    while (m--)
    {
        string s;
        cin >> s;

        if (s == "get")
        {
            int u;
            cin >> u;
            u--;
            u = find(u);
            cout << mn[u] + 1 << ' ' << mx[u] + 1 << ' ' << sze[u] << nl;
        }
        else
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            merge(u, v);
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
