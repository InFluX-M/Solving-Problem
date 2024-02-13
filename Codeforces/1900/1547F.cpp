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
int t = 1;

void solve()
{
    int n;
    cin >> n;

    vi s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<vi> GMQ(log2(n) + 2, vi(n, -1));

    for (int i = 0; i < n; i++)
        GMQ[0][i] = s[i];

    for (int i = 1; i <= log2(n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            GMQ[i][j] = __gcd(GMQ[i - 1][j], GMQ[i - 1][(j + (1 << (i - 1))) % n]);
        }
    }

    vi p(n + 1);
    p[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = log2(i);
    }

    int l = 0, r = n - 1;

    int res = n - 1;
    unordered_set<int> pq;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        for (int i = 0; i < n; i++)
        {
            if (mid == 0)
            {
                pq.insert(GMQ[0][i]);
            }
            else
            {
                int pw = p[mid];
                int r2 = i + mid - (1 << pw) + 1;
                if (r2 < 0)
                    r2 += n;
                r2 %= n;

                pq.insert(__gcd(GMQ[pw][i], GMQ[pw][r2]));
            }
        }

        if (sz(pq) <= 1)
        {
            res = min(res, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

        pq.clear();
    }

    cout << res << endl;
    return;
}

int32_t main()
{
    fastio;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
