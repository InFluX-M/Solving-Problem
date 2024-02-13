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

    int k;
    cin >> k;

    queue<pii> q;
    vector<bool> vis(n * m, false);
    vector<int> dis(n * m, INT_MAX);
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        q.push({l, r});
        vis[l * m + r] = true;
        dis[l * m + r] = 0;
    }

    while (!q.empty())
    {
        pii u = q.front();
        q.pop();

        if (u.F > 0 && !vis[(u.F - 1) * m + u.S])
        {
            q.push({u.F - 1, u.S});
            dis[(u.F - 1) * m + u.S] = dis[u.F * m + u.S] + 1;
            vis[(u.F - 1) * m + u.S] = true;
        }
        if (u.F < n - 1 && !vis[(u.F + 1) * m + u.S])
        {
            q.push({u.F + 1, u.S});
            dis[(u.F + 1) * m + u.S] = dis[u.F * m + u.S] + 1;
            vis[(u.F + 1) * m + u.S] = true;
        }
        if (u.S > 0 && !vis[u.F * m + u.S - 1])
        {
            q.push({u.F, u.S - 1});
            dis[u.F * m + u.S - 1] = dis[u.F * m + u.S] + 1;
            vis[u.F * m + u.S - 1] = true;
        }
        if (u.S < m - 1 && !vis[u.F * m + u.S + 1])
        {
            q.push({u.F, u.S + 1});
            dis[u.F * m + u.S + 1] = dis[u.F * m + u.S] + 1;
            vis[u.F * m + u.S + 1] = true;
        }
    }

    int ix = 0, jx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dis[ix * m + jx] < dis[i * m + j])
                ix = i, jx = j;

    cout << ix + 1 << ' ' << jx + 1;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
