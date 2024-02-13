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
    vector<string> p = {"L", "R"};
    map<string, int> s;
    map<int, string> r;

    int idx = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int z = 0; z < 2; z++)
                {
                    string t = p[i] + " " + p[j] + " " + p[k] + " " + p[z];
                    if (p[i] != p[k] && (p[k] == p[j] || p[k] == p[z]))
                        continue;
                    s[p[i] + " " + p[j] + " " + p[k] + " " + p[z]] = idx, r[idx++] = p[i] + " " + p[j] + " " + p[k] + " " + p[z];
                }

    vector<set<int>> g(sz(s), set<int>());
    for (int i = 0; i < sz(s); i++)
    {
        string c = r[i];
        c[0] = c[0] == 'R' ? 'L' : 'R';
        if (s.find(c) != s.end())
            g[i].insert(s[c]);
        

        for (int j = 1; j < 4; j++)
        {
            if (r[i][0] == r[i][2 * j])
            {
                string q = c;
                q[2 * j] = c[0];
                if (s.find(q) == s.end())
                    continue;
                g[i].insert(s[q]);
            }
        }
    }

    string a, b;
    getline(cin, a);
    getline(cin, b);

    int origin = s[a];
    int dest = s[b];

    vector<vector<string>> dis(sz(s), vector<string>());
    vector<bool> vis(sz(s), false);
    queue<int> q;
    q.push(origin);
    dis[origin].push_back(a);
    vis[origin] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                dis[v] = dis[u];
                dis[v].pb(r[v]);
                q.push(v);
            }
        }
    }

    for (string t : dis[dest])
        cout << t << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
