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

    vector<bool> vis(1e5, false);
    vector<int> dis(1e5, INT_MAX);
    queue<int> q;
    q.push(n);
    vis[n] = true;
    dis[n] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u - 1 > 0 && !vis[u - 1])
        {
            dis[u - 1] = dis[u] + 1;
            vis[u - 1] = true;
            q.push(u - 1);
            if (u - 1 == m)
                break;
        }
        if (2 * u < 1e5 && !vis[2 * u])
        {
            dis[2 * u] = dis[u] + 1;
            vis[2 * u] = true;
            q.push(2 * u);
            if (2 * u == m)
                break;
        }
    }

    cout << dis[m];
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
