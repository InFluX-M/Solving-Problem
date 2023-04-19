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

bool compareMoney(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.F >= b.F;
}

int main()
{
    fastio;

    int n, t;
    cin >> n >> t;

    vector<pii> a;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(mp(x, y));
    }

    sort(a.begin(), a.end(), compareMoney);

    ll price = 0;
    vector<int> BankT(48, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i].S > t)
            continue;

        if (BankT[a[i].S] == 0)
        {
            BankT[a[i].S] = a[i].first;
            price += BankT[a[i].S];
        }
    }

    cout << price;
    return 0;
}
