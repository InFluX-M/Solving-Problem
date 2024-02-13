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
    int n, x;
    cin >> n >> x;

    vi s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<bool>> dpl(n + 1, vector<bool>(x + 1, false));
    vector<vector<bool>> dpr(n + 1, vector<bool>(x + 1, false));

    dpl[0][0] = true;
    dpr[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (dpl[i - 1][j])
                dpl[i][j] = true;

            if (!dpl[i][j] && j - s[i-1] >= 0 && dpl[i - 1][j - s[i-1]])
            {
                dpl[i][j] = dpl[i - 1][j - s[i-1]];
            }
        }
    }

    reverse(all(s));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (dpr[i - 1][j])
                dpr[i][j] = true;

            if (!dpr[i][j] && j - s[i-1] >= 0 && dpr[i - 1][j - s[i-1]])
            {
                dpr[i][j] = dpr[i - 1][j - s[i-1]];
            }
        }
    }
    reverse(all(s));

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int t = 0; t <= x; t++)
        {
            if (dpl[i][t] && dpr[n - i - 1][x - t])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            res.push_back(s[i]);
    }

    cout << sz(res) << nl;
    for (int i = 0; i < sz(res); i++)
    {
        cout << res[i] << ' ';
    }
}

int32_t main()
{
    fastio;
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
