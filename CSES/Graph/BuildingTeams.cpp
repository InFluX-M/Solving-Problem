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
const int maxn = 1e5;
vector<int> g[maxn];
vector<bool> vis(maxn, false);
vector<int> team(maxn);
bool cycle = false;

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    queue<int> q;
    q.push(0);

    vector<int> part(n, -1);

    bool valid = true;

    for (int i = 0; i < n && valid; i++)
    {
        if (part[i] == -1)
        {
            q.push(i);
            part[i] = 0;

            while (!q.empty() && valid)
            {
                int u = q.front();
                q.pop();

                for (int v : g[u])
                {
                    if (part[v] == part[u])
                    {
                        valid = false;
                        break;
                    }

                    if (part[v] == -1)
                    {
                        part[v] = 1 - part[u];
                        q.push(v);
                    }
                }
            }
        }
    }

    if (valid)
    {
        for (int i = 0; i < n; i++)
        {
            cout << part[i] + 1 << ' ';
        }
    }
    else
        cout << "IMPOSSIBLE";
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
