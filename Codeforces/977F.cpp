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

    map<int, int> s;
    vi p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    for (int i = 0; i < n; i++)
    {
        if (s.find(p[i] - 1) != s.end())
            s[p[i]] = max(s[p[i]], s[p[i] - 1] + 1);
        else
            s[p[i]] = max(s[p[i]], 1);
    }

    int ans = 0;
    int last = -1;
    for (auto it : s)
    {
        if (it.S > ans)
        {
            ans = it.S;
            last = it.F;
        }
    }
    cout << ans << endl;

    vi res;
    while (ans--)
    {
        res.pb(last);
        last--;
    }

    reverse(all(res));

    map<int, int> lastIndex;
    for (int i = 0; i < n; i++)
        lastIndex[p[i]] = i;

    for (int i = 0; i < sz(res); i++)
        cout << lastIndex[res[i]]  + 1<< " ";
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
