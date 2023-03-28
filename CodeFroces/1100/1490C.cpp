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
        ll n;
        cin >> n;

        bool flg = false;
        for (ll i = 1; i * i * i <= n; i++)
        {
            ll rem = n - i * i * i;

            ll l = 1, r = sqrt(n);
            ll aim = -1;

            // if(i == 5779)
            // {
            //     cout << "H";
            // }
            
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                if (rem == mid * mid * mid)
                {
                    aim = mid;
                    flg = true;
                    break;
                }
                else if (rem < mid * mid * mid)
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }

            if (flg)
            {
                cout << "YES";
                break;
            }
        }

        if (!flg)
            cout << "NO";
        cout << "\n";
    }

    return 0;
}
