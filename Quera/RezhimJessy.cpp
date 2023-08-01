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
    int n, W;
    cin >> n >> W;

    vl a;
    for (int i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        a.push_back(t);
    }

    int i = 0, j = 1;
    ll res = 0, now = a[0];
    while (j < n)
    {
        now = a[i];
        while (j < n && now + a[j] <= W)
        {
            now += a[j];
            j++;
        }
        if (now <= W && now > res)
            res = now;
        now -= a[i];
        i++;
    }

    cout << res;

    return 0;
}
