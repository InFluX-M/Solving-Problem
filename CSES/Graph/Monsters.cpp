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
 
int n, m;
bool valid(int i, int j)
{
    return (i < n && i >= 0 && j < m && j >= 0);
}
 
void solve()
{
    cin >> n >> m;
 
    vector<pii> st = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<char> sc = {'D', 'U', 'R', 'L'};
 
    vector<vector<char>> g(n, vector<char>(m));
    int is, js;
    queue<pii> q;
    vector<vi> dis(n, vi(m, 1e9));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<pii> aim;
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
                is = i, js = j;
 
            if (g[i][j] == 'M')
            {
                q.push({i, j});
                dis[i][j] = 0;
                vis[i][j] = true;
            }
 
            if (g[i][j] != '#' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                aim.pb({i, j});
        }
 
    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            if (valid(u.F + st[i].F, u.S + st[i].S) && g[u.F + st[i].F][u.S + st[i].S] != '#' && !vis[u.F + st[i].F][u.S + st[i].S])
            {
                vis[u.F + st[i].F][u.S + st[i].S] = true;
                dis[u.F + st[i].F][u.S + st[i].S] = dis[u.F][u.S] + 1;
                q.push({u.F + st[i].F, u.S + st[i].S});
            }
        }
    }
 
    vector<vi> path(n, vi(m));
    vector<vi> dis1(n, vi(m, 1e9));
    vector<vector<bool>> vis1(n, vector<bool>(m, false));
    q.push({is, js});
    dis1[is][js] = 0;
    vis1[is][js] = true;
    path[is][js] = -1;
 
    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            if (valid(u.F + st[i].F, u.S + st[i].S) && g[u.F + st[i].F][u.S + st[i].S] == '.' && !vis1[u.F + st[i].F][u.S + st[i].S])
            {
                vis1[u.F + st[i].F][u.S + st[i].S] = true;
                dis1[u.F + st[i].F][u.S + st[i].S] = dis1[u.F][u.S] + 1;
                path[u.F + st[i].F][u.S + st[i].S] = i;
                q.push({u.F + st[i].F, u.S + st[i].S});
            }
        }
    }
 
    pii a = {-1, -1};
    int lA = INT_MAX;
 
    for (pii t : aim)
    {
        if (dis[t.first][t.second] > dis1[t.first][t.second] && lA > dis1[t.first][t.second])
        {
            a = t;
            lA = dis1[t.first][t.second];
        }
    }
 
    if (lA == INT_MAX)
        cout << "NO";
    else
    {
        cout << "YES" << nl;
        cout << lA << nl;
 
        string pathF = "";
        int i = a.first, j = a.second;
 
        while (i != is || j != js)
        {
            pathF.pb(sc[path[i][j]]);
            int tmp = path[i][j];
            i -= st[tmp].first;
            j -= st[tmp].second;
        }
 
        reverse(all(pathF));
        cout << pathF;
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