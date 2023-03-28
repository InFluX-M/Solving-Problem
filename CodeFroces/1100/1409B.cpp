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
    fastio

        int t;
    cin >> t;

    while (t--)
    {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        if (a < b)
        {
            if (n >= a - x)
            {
                n -= (a - x);
                a = x;

                if (n >= b - y)
                {
                    b = y;
                }
                else
                    b -= n;
            }
            else
            {
                a -= n;
                n = 0;
            }
        }
        else
        {
            if (n >= b - y)
            {
                n -= (b - y);
                b = y;

                if (n >= a - x)
                {
                    a = x;
                }
                else
                    a -= n;
            }
            else
            {
                b -= n;
                n = 0;
            }
        }

        cout << a * b << endl;
    }

    return 0;
}
