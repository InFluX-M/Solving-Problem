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

const int mxn = 1e3 + 1;
string g[mxn];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char d[4] = {'D', 'L', 'R', 'U'};

int n, m, k;
string path, aim;
bool finds = false;
int xs, ys;

bool valid(int x, int y)
{
    return (x < n && y < m && x >= 0 && y >= 0);
}

void solve()
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> g[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'X')
                xs = i, ys = j;

    if (k % 2)
        cout << "IMPOSSIBLE";
    else
    {
        queue<pair<int, int>> q;

        vector<vi> par(n, vi(m, -1));
        vector<vi> dis(n, vi(m, 1e9));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int ax = -1, ay = -1;

        q.push({xs, ys});
        visited[xs][ys] = true;
        dis[xs][ys] = 0;

        while (!q.empty())
        {
            pii u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int vx = u.F + dx[i];
                int vy = u.S + dy[i];
                if (valid(vx, vy) && !visited[vx][vy] && g[vx][vy] != '*')
                {
                    dis[vx][vy] = dis[u.F][u.S] + 1;
                    par[vx][vy] = i;
                    q.push({vx, vy});
                    visited[vx][vy] = true;
                }
            }
        }

        cout << "IMPOSSIBLE";
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
