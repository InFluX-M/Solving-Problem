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

    int r, c;
    cin >> r >> c;

    int x, y;
    cin >> x >> y;

    n += 2;
    m += 2;

    vector<vi> g(n, vi(m, 0));
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = 1; j <= m - 2; j++)
        {
            char c;
            cin >> c;
            g[i][j] = (c == '.');
        }
    }

    vector<int> dis(n * m, INT_MAX);
    vector<bool> vis(n * m, false);

    dis[r * m + c] = 0;

    vector<pii> s = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (int i = 0; i < n * m - m; i++)
    {
        int idx = 0, mn = INT_MAX;
        for (int j = m; j < n * m - m; j++)
        {
            int r1 = j / m;
            int c1 = j % m;
            if (vis[j] && g[r1][c1])
                continue;
            if (dis[j] < mn)
            {
                mn = dis[j];
                idx = j;
            }
        }

        if (mn == INT_MAX)
            break;
            
        vis[idx] = true;
        int r1 = idx / m;
        int c1 = idx % m;

        for (int j = 0; j < 4; j++)
        {
            if (g[r1 + s[j].F][c1 + s[j].S])
            {
                dis[(r1 + s[j].F) * m + c1 + s[j].S] = min(dis[(r1 + s[j].F) * m + c1 + s[j].S], dis[idx] + (s[j].S == -1));
            }
        }
    }

    cout << 5;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
