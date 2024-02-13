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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> s;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--, v--;
        w *= -1;

        s.pb(make_tuple(u, v, w));
    }

    vector<ll> dist(n, 1e18);
    dist[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = get<0>(s[j]);
            int v = get<1>(s[j]);
            int weight = get<2>(s[j]);
            if (dist[u] != 1e18 && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    bool valid = true;
    for (int i = 0; i < m; i++)
    {
        int u = get<0>(s[i]);
        int v = get<1>(s[i]);
        int weight = get<2>(s[i]);
        if (dist[u] != 1e18 && dist[u] + weight < dist[v])
        {
            dist[v] = dist[u] + weight;
            valid = false;
            break;
        }
    }

    cout << ((valid) ? -1 * dist[n - 1] : -1);
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
