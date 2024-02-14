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
 
    vector<vector<char>> g(n, vector<char>(m));
 
    int iA = -1, iB = -1, jA = -1, jB = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                iA = i;
                jA = j;
            }
            if (g[i][j] == 'B')
            {
                iB = i;
                jB = j;
            }
        }
    }
 
    vector<pii> step = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<char> s = {'R', 'D', 'U', 'L'};
 
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, false));
    vector<vector<char>> path(n, vector<char>(m, 'n'));
 
    dis[iA][jA] = 0;
    vis[iA][jA] = true;
    path[iA][jA] = ' ';
 
    queue<pii> q;
    q.push({iA, jA});
 
    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            if (!valid(u.F + step[i].F, u.S + step[i].S))
                continue;
            if (g[u.F + step[i].F][u.S + step[i].S] != '#' && !vis[u.F + step[i].F][u.S + step[i].S])
            {
                vis[u.F + step[i].F][u.S + step[i].S] = true;
                dis[u.F + step[i].F][u.S + step[i].S] = dis[u.F][u.S] + 1;
                path[u.F + step[i].F][u.S + step[i].S] = s[i];
                q.push({u.F + step[i].F, u.S + step[i].S});
            }
        }
    }
 
    if (!vis[iB][jB])
        cout << "NO" << nl;
    else
    {
        string res = "";
 
        int i = iB, j = jB;
        while (i != iA || j != jA)
        {
            if (path[i][j] == 'n')
            {
                cout << "NO" << nl;
                return;
            }
            if (path[i][j] == 'R')
            {
                j--;
                res.push_back('R');
            }
            if (path[i][j] == 'D')
            {
                i--;
                res.push_back('D');
            }
            if (path[i][j] == 'U')
            {
                i++;
                res.push_back('U');
            }
            if (path[i][j] == 'L')
            {
                j++;
                res.push_back('L');
            }
        }
 
        reverse(all(res));
        cout << "YES" << nl;
        cout << dis[iB][jB] << nl;
        cout << res;
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