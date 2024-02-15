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

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

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

    int n, x0, y0;
    cin >> n >> x0 >> y0;

    set<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        s.insert(mp(x - x0, y - y0));
    }

    ll ans = 0;
    while (!s.empty())
    {
        pii m = *s.begin();
        s.erase(s.begin());

        int x = m.F, y = m.S;
        set<pii> s1;
        for (pii i : s)
        {
            int x1 = i.F, y1 = i.S;
            if (x1 * y == x * y1)
                s1.insert(i);
        }

        for (pii i : s1)
            s.erase(i);
        ans++;
    }

    cout << ans;

    return 0;
}
