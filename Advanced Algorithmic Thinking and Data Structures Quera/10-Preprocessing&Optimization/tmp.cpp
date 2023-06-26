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

int main()
{
    fastio;
    int n, q;
    cin >> n >> q;

    vector<vi> a(n, vector<int>(n));
    vector<vi> pre(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            pre[i][j] = (j == 0) ? a[i][j] : pre[i][j - 1] + a[i][j];
        }

    for (int j = 0; j < n; j++)
        for (int i = 1; i < n; i++)
            pre[i][j] += pre[i - 1][j];

    while (q--)
    {
        int x, y, X, Y;
        cin >> x >> y >> X >> Y;
        ll k = (x == 0) ? ((y == 0) ? pre[X][Y] : pre[X][Y] - pre[X][y - 1]) : ((y == 0) ? pre[X][Y] - pre[x - 1][Y] : pre[X][Y] - pre[x - 1][Y] - pre[X][y - 1] + pre[x - 1][y - 1]);
        cout << k << '\n';
    }

    return 0;
}
