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
        int n, x;
        cin >> n >> x;
        map<ll, ll> a;
        for (int i = 0; i < n; i++)
        {
            ll p;
            cin >> p;
            a[p]++;
        }

        ll res = 0;
        for (pll c : a)
        {
            while (c.second > 0)
            {

                if (a.find(1LL * c.first * x) != a.end() && a[1LL * c.first * x] > 0)
                    a[1LL * c.first * x]--;
                else
                    res++;
                c.second--;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
