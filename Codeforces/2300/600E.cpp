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

const int MAX_N = 1e5 + 14;

int n, c[MAX_N], ans[MAX_N];
vector<int> g[MAX_N];
unordered_map<int, int> cnt[MAX_N];
long long sum[MAX_N];
int mx[MAX_N], sz[MAX_N];

void updateSize(int u, int p)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        updateSize(v, u);
        sz[u] += sz[v];
    }
}

void upg(int u, int c)
{
    if (cnt[u][c] > mx[u])
    {
        sum[u] = c;
        mx[u] = cnt[u][c];
    }
    else if (cnt[u][c] == mx[u])
    {
        sum[u] += c;
    }
}

void dfs(int u, int p)
{
    int big_size = 0, idx = -1;
    for (int v : g[u])
    {
        if (v != p)
        {
            dfs(v, u);
            if (big_size < sz[v])
            {
                big_size = sz[v];
                idx = v;
            }
        }
    }

    if (big_size > 0)
    {
        mx[u] = mx[idx];
        sum[u] = sum[idx];
        swap(cnt[u], cnt[idx]);
    }

    cnt[u][c[u]]++;
    upg(u, c[u]);

    for (int v : g[u])
    {
        if (v == p || v == idx)
            continue;
        for (pii co : cnt[v])
        {
            cnt[u][co.F] += co.S;
            upg(u, co.F);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    updateSize(0, -1);
    dfs(0, -1);

    for (int i = 0; i < n; i++)
        cout << sum[i] << ' ';
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}