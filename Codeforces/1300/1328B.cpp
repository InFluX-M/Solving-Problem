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
        int n, k;
        cin >> n >> k;

        int a = 0;
        bool flg = false;
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = n; j > i; j--)
            {
                a++;
                if (a == k)
                {
                    string s = "";
                    for (int i = 0; i < n; i++)
                        s += 'a';
                    s[i - 1] = 'b';
                    s[j - 1] = 'b';
                    flg = true;
                    cout << s << "\n";
                    break;
                }
            }

            if (flg)
                break;
        }
    }

    return 0;
}
