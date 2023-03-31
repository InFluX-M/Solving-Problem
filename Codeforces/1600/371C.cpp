#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll mod = 1e9 + 7;

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2")

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

ll mul(ll a, ll b)
{
    return (a % mod) * (b % mod) % mod;
}

ll min(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll sum(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    fastio;

    string s;
    cin >> s;

    int q[3];
    fill_n(q, 3, 0);
    for (int c : s)
    {
        if (c == 'B')
            q[0]++;
        else if (c == 'S')
            q[1]++;
        else
            q[2]++;
    }

    int n[3];
    cin >> n[0] >> n[1] >> n[2];

    int p[3];
    cin >> p[0] >> p[1] >> p[2];

    ll r;
    cin >> r;

    ll ans = 0;
    ll l = 0, h = 1e13;
    while (l <= h)
    {
        ll m = (l + h) / 2;
        ll cost = 0;
        for (int i = 0; i < 3; i++)
        {
            if (q[i] * m > n[i])
                cost += (q[i] * m - n[i]) * p[i];
        }
        if (cost <= r)
        {
            ans = m;
            l = m + 1;
        }
        else
            h = m - 1;
    }

    cout << ans;

    return 0;
}
