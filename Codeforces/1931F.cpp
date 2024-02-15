#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
using pqg = priority_queue<T>;
template <class T>
using pql = priority_queue<T, vector<T>, greater<T>>;

const ll inf = 1e18;
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
#define lb lower_bound
#define ub upper_bound
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

const int mxn = 2e5 + 4;
vi g[mxn];
vi visited(mxn, 0);
bool cycle = false;

bool dfs(int u)
{
    visited[u] = 1;
    for (int v : g[u])
    {
        if (visited[v] == 1)
        {
            cycle = true;
            return true;
        }

        if (visited[v] == 0 && dfs(v))
        {
            cycle = true;
            return true;
        }
    }
    visited[u] = 2;
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        vi tmp(n);
        cin >> tmp[0];
        for (int j = 1; j < n; j++)
        {
            cin >> tmp[j];
            if (j > 1)
                g[tmp[j - 1] - 1].pb(tmp[j] - 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dfs(i))
            break;
    }

    cout << ((cycle) ? "NO\n" : "YES\n");
    
    for (int i = 0; i < n; i++)
        visited[i] = 0, g[i].clear();

    cycle = false;
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
