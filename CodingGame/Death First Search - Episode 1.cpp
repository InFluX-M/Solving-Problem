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

int solve()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e;
    cin.ignore();

    vector<vi> adj(n, vi(n, 0));
    for (int i = 0; i < l; i++)
    {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
        cin.ignore();
    }

    vector<int> gateways;
    for (int i = 0; i < e; i++)
    {
        int ei; // the index of a gateway node
        cin >> ei;
        gateways.pb(ei);
        cin.ignore();
    }

    // game loop
    while (1)
    {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si;
        cin.ignore();

        vector<vi> dis(n, vi());
        vector<bool> vis(n, false);

        dis[si].push_back(si);
        vis[si] = true;

        queue<int> q;
        q.push(si);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int i = 0; i < n; i++)
            {
                if (adj[u][i] && !vis[i])
                {
                    vis[i] = true;
                    dis[i] = dis[u];
                    dis[i].push_back(i);
                    q.push(i);
                }
            }
        }

        int eR = -1;
        for (int i = 0; i < e; i++)
        {
            if (dis[gateways[i]].size() == 0) continue;

            if (eR == -1 || dis[gateways[i]].size() < dis[eR].size())
                eR = gateways[i];
        }

        int s = dis[eR].size();

        adj[dis[eR][s - 1]][dis[eR][s - 2]] = 0;
        adj[dis[eR][s - 2]][dis[eR][s - 1]] = 0;

        cout << dis[eR][s - 1] << ' ' << dis[eR][s - 2] << endl;
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
