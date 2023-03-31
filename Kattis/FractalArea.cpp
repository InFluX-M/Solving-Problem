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

    int t;
    cin >> t;

    while (t--)
    {
        int r, n;
        cin >> r >> n;

        long double s = r * r;
        ll counter = 4;

        for (int i = 2; i <= n; i++)
        {
            if (i == 2)
                s += 4 * (1.0 * r / 2 * r / 2);
            else
            {
                counter *= 3;
                long double rP = 1.0 * r / pow(2, (n - 1));
                s += counter * (rP * rP);
            }
        }

        cout << fixed << showpoint << setprecision(8) << s * M_PI << "\n";
    }

    return 0;
}
