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
    ll n, k;
    cin >> n >> k;

    vector<ll> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(all(s));
    vector<ll> sn(n / 2 + 1);
    for (int i = n / 2; i < n; i++)
        sn[i - n / 2] = s[i];

    n = n / 2 + 1;
    ll res = sn[0];
    ll num = upper_bound(all(sn), res) - sn.begin();

    while (k > 0)
    {
        ll t = upper_bound(all(sn) + num, res) - sn.begin();
        if (t >= n)
        {
            res += (k / n);
            k = 0;
        }
        else
        {
            ll total = (sn[t] - res) * t;
            if (k >= total)
            {
                res += (sn[t] - res);
                k -= total;
                num = t;
            }
            else
            {
                ll u = k / t;
                res += u;
                k = 0;
            }
        }
    }

    cout << res;
    return 0;
}
