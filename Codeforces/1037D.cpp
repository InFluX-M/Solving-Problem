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

vector<int> res(2 * pow(10, 5) + 2);
bool cmp(int a, int b)
{
    return res[a] < res[b];
}

void solve()
{
    int n;
    cin >> n;

    vector<vi> g(n, vi());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vi s;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        res[t - 1] = i;
        s.push_back(t - 1);
    }
    for (int i = 0; i < n; i++)
    {
        sort(all(g[i]), cmp);
    }

    vector<bool> vis(n, false);
    queue<int> q;
    vis[0] = true;
    q.push(0);

    int i = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (s[i] != u)
        {
            cout << "No";
            return;
        }
        else
        {
            i++;
        }

        for (int v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    cout << "Yes";
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
