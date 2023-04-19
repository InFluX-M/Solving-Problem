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
#define FOR(a, n) for(int i = 0; i < n; i++) cout << res[i] << " ";

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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<pair<int, int>> s;
    s.push(make_pair(a[0], 1));

    int res[n];
    int idx = 0;
    res[idx++] = 1;

    for (int i = 1; i < n; i++)
    {
        int val = 1;
        while (!s.empty() && s.top().first < a[i])
        {
            val += s.top().second;
            s.pop();
        }
        s.push(make_pair(a[i], val));
        res[idx++] = val;
    }

    FOR(res, n);

    return 0;
}
