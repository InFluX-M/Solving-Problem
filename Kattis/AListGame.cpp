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

vector<int> sieveOfEratosthenes(int l, int r)
{
    vector<bool> a(r + 1, true);
    vector<int> primes;

    for (int i = 2; i * i <= r; i++)
    {
        if (a[i])
        {
            if (i >= l && i <= r)
                primes.push_back(i);
            for (int j = i * i; j <= r; j += i)
                a[j] = false;
        }
    }

    for (int i = sqrt(r) + 1; i <= r; i++)
    {
        if (a[i])
            primes.push_back(i);
    }

    return primes;
}

int main()
{
    fastio;

    int X;
    cin >> X;

    int starting_range = 1;
    int ending_range = sqrt(X) + 1;

    vector<int> result = sieveOfEratosthenes(starting_range, ending_range);

    int res = 0;
    for (int u : result)
    {
        while (X % u == 0)
        {
            res++;
            X /= u;
        }
    }

    cout << ((res == 0) ? 1 : res);

    return 0;
}
