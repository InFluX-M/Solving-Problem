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

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> largestLeft(n);
    largestLeft[0] = a[0];

    vector<ll> lowestRight(n);
    lowestRight[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        if (largestLeft[i - 1] < a[i])
            largestLeft[i] = a[i];
        else
            largestLeft[i] = largestLeft[i - 1];

        if (lowestRight[n - i] > a[n - i - 1])
            lowestRight[n - i - 1] = a[n - i - 1];
        else
            lowestRight[n - i - 1] = lowestRight[n - i];
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (lowestRight[i + 1] > a[i])
                res++;
        }
        else if (i == n - 1)
        {
            if (largestLeft[i - 1] < a[i])
                res++;
        }
        else
        {
            if (largestLeft[i - 1] < a[i] && lowestRight[i + 1] > a[i])
                res++;
        }
    }

    cout << res;
    return 0;
}
