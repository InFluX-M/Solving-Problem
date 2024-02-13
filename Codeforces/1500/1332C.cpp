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

int const mxn = 2e5 + 1;
int par[mxn];

int find(int u)
{
    return par[u] == -1 ? u : par[u] = find(par[u]);
}

void merge(int u, int v)
{
    if ((u = find(u)) == (v = find(v)))
        return;

    par[v] = u;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }

    for (int i = 0; i < n / 2; i++)
    {
        merge(i, n - 1 - i);
    }

    for (int i = 0; i < n - k; i++)
    {
        merge(i, i + k);
    }

    for (int i = 0; i < n; i++)
    {
        find(i);
    }

    unordered_map<int, vi> res;
    for (int i = 0; i < n; i++)
        if (par[i] != -1)
            res[par[i]].pb(i);

    ll aim = 0;
    for (pair<int, vi> t : res)
    {
        vi charc(26, 0);
        charc[s[t.F] - 'a']++;

        int mx = 0;

        for (int u : t.S)
        {
            charc[s[u] - 'a']++;
            mx = max(mx, charc[s[u] - 'a']);
        }

        aim += (t.S.size() + 1 - mx);
    }

    cout << aim << nl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
