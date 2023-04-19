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

bool isPrime(long long N)
{
    if (N == 1)
        return 0;

    for (long long i = 2; i <= sqrt(N); i++)
    {
        if (N % i == 0)
            return 0;
    }

    return 1;
}

long long primeProduct(long long M, long long N)
{
    long long ans = 1;

    for (long long i = M; i <= N; i++)
    {
        if (isPrime(i))
            ans = mul(ans, i);
    }

    return ans;
}

int main()
{
    fastio;
    int l, r;
    cin >> l >> r;

    cout << primeProduct(l, r);
    return 0;
}
