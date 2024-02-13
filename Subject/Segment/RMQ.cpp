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
    int n;
    cin >> n;

    int q;
    cin >> q;

    vi s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<vi> rmq(log2(n) + 1, vi(n, -1));
    for (int i = 0; i < n; i++)
        rmq[0][i] = s[i];

    for (int i = 1; i <= log2(n); i++)
    {
        for (int j = 0; j <= n - (1 << i); j++)
        {
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << i - 1)]);
        }
    }

    vi powN(n + 1);
    powN[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        powN[i] = log2(i);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int pN = powN[r - l + 1];

        if (l == r)
            cout << s[l] << endl;
        else
            cout << min(rmq[pN][l], rmq[pN][r - (1 << pN) + 1]) << endl;
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
