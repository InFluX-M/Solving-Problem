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

const int mxn = 2e5 + 1;

struct DSU
{
public:
    int *rnk;
    int *par;

    DSU()
    {
        rnk = new int[mxn];
        par = new int[mxn];

        for (int i = 0; i < mxn; i++)
            par[i] = -1;
    }

    int find(int u)
    {
        return par[u] == -1 ? u : par[u] = find(par[u]);
    }

    void merge(int u, int v)
    {
        if ((u = find(u)) == (v = find(v)))
            return;

        if (rnk[u] < rnk[v])
            swap(u, v);

        if (rnk[u] >= rnk[v])
        {
            rnk[u] = max(rnk[u], rnk[v] + 1);
            par[v] = u;
        }
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    DSU *dsu1 = new DSU();
    DSU *dsu2 = new DSU();

    while (q--)
    {
        int w, u, v;
        cin >> w >> u >> v;

        if (w == 3)
        {
            u = dsu1->find(u);
            v = dsu1->find(v);

            if (u == v)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (w == 1)
        {
            dsu1->merge(u, v);
        }
        else
        {
            for (int i = u; i < v; i++)
            {
                int l = i + 1, r = n;
                int res = n;
                while (l <= r)
                {
                    int mid = (l + r) / 2;

                    int m = dsu2->find(mid);
                    int p = dsu2->find(i);

                    if (m == p)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                        res = min(res, mid);
                    }
                }

                if (res > v)
                    break;

                dsu1->merge(i, res);
                dsu2->merge(i, res);

                i = res - 1;
            }
        }
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
