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
const int mxn = 1e6 + 5;
int n, q;
ll node[mxn * 2];

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> node[i + n];

    for (int i = n - 1; i > 0; i--)
        node[i] = node[2 * i] ^ node[2 * i + 1];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        r++;

        l += n, r += n;

        int ans = 0;

        while (l < r)
        {
            if (l % 2 == 1)
                ans ^= node[l++];

            if (r % 2 == 1)
                ans ^= node[--r];

            l /= 2, r /= 2;
        }

        cout << ans << endl;
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
