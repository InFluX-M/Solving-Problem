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

const int mxn = 5e4 + 2;
vi g[mxn];
set<int, greater<int>> par[mxn];
int h[mxn];

int find(int u)
{
    return *par[u].begin() == -1 ? find(*par[u].begin());
}

void merge(int u, int v)
{
    if ((u = find(u)) == (v = find(v)))
        return;

    if (h[u] < h[v])
        swap(u, v);

    par[v].insert(u);

    h[u] += (h[v] == h[u]);
}

void cut(int u, int v)
{
    par[u].erase(v);
    par[v].erase(u);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        par[u].insert(v);
        par[v].insert(u);
    }

    while (k--)
    {
        string s;
        cin >> s;
        int u, v;
        cin >> u >> v;

        if(s == "cut")
        {
            cut(u, v);
        }
        else
        {
            
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
