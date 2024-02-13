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
int par[mxn];
vi w(mxn);
vi s(mxn, 0);
int n;

int find(int u)
{
    return par[u] == -1 ? u : par[u] = find(par[u]);
}

void merge(int u, int v)
{
    if ((u = find(u)) == (v == find(v)))
        return;

    if (u < v)
        swap(u, v);

    par[v] = u;
}

void add(int p, int x)
{
    if (s[p] + x <= w[p])
    {
        s[p] += x;
        return;
    }

    if (s[p] + x > w[p])
    {
        x -= (w[p] - s[p]);
        s[p] = w[p];

        if (p == n - 1)
            return;
        par[p] = p + 1;

        p = find(p);

        if (p == -1)
            return;

        add(p, x);
    }
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        cin >> w[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int t;

        cin >> t;

        if (t == 1)
        {
            int p, x;
            cin >> p >> x;
            p--;

            add(p, x);
        }
        else
        {
            int p;
            cin >> p;
            p--;

            if (par[p] == -1)
                cout << s[p];
            else
                cout << w[p];

            cout << nl;
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
