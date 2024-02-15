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

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        ll n, w;
        cin >> n >> w;
        vector<pii> a;
        for (int i = 0; i < n; i++)
        {
            ll p;
            cin >> p;
            a.push_back({p, i});
        }
        sort(all(a));

        ll c = 0;
        vector<ll> res;

        for (int i = n - 1; i >= 0; i--)
        {
            if (c + a[i].first <= w)
            {
                c += a[i].first;
                res.push_back(a[i].second);
            }
        }

        if (c >= ceil(1.0 * w / 2))
        {
            sort(all(res));
            cout << sz(res) << '\n';
            for (ll u : res)
                cout << u + 1 << ' ';
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }

    return 0;
}
