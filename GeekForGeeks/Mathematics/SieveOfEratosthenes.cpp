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

vector<int> sieveOfEratosthenes(int N)
{
    vector<bool> a(N + 1, true);
    vector<int> primes;

    for (int i = 2; i * i <= N; i++)
    {
        if (a[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
                a[j] = false;
        }
    }

    for (int i = sqrt(N) + 1; i <= N; i++)
    {
        if (a[i])
            primes.push_back(i);
    }

    return primes;
}

int main()
{
    fastio;
    int N;
    cin >> N;

    vector<int> p = sieveOfEratosthenes(N);
    for (int u : p)
        cout << u << " ";

    return 0;
}
