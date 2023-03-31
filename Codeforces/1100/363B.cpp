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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
    int n, k;
    cin >> n >> k;

    vi h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int sums[n];
    sums[0] = h[0];
    for (int i = 1; i < n; i++)
        sums[i] = sums[i - 1] + h[i];

    int ans = sums[k - 1];
    int ix = 0;

    for (int i = 1; i <= n - k; i++)
        if (ans > sums[i + k - 1] - sums[i - 1])
        {
            ans = sums[i + k - 1] - sums[i - 1];
            ix = i;
        }   

    cout << ix + 1;
    return 0;
}
