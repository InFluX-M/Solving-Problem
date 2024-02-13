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

        vector<int> adj[n];
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        vector<int> dis(n);
        vector<bool> vis(n, false);
        vector<int> path(n);

        dis[0] = 0;
        vis[0] = true;
        path[0] = -1;

        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    dis[v] = dis[u] + 1;
                    vis[v] = true;
                    path[v] = u;
                    q.push(v);
                }
            }
        }

        if (!vis[n - 1])
        {
            cout << "IMPOSSIBLE";
            return;
        }

        int v = n - 1;
        vi res;

        while (v != -1)
        {
            res.pb(v + 1);
            v = path[v];
        }

        cout << sz(res) << nl;
        for (int i = sz(res) - 1; i >= 0; i--)
            cout << res[i] << ' ';
    }

    int32_t main()
    {
        fastio;
        int t = 1;
        while (t--)
            solve();

        return 0;
    }
