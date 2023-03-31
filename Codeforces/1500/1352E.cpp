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
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<int, int> s;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s[a[i]]++;
        }

        int ps[n];
        ps[0] = a[0];
        for (int i = 1; i < n; i++)
            ps[i] = ps[i - 1] + a[i];

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i == 0 && s.find(ps[j]) != s.end())
                {
                    if (s[ps[j]] > 0)
                    {
                        ans += s[ps[j]];
                        s[ps[j]] = 0;
                    }
                }
                if (i > 0 && s.find(ps[j] - ps[i - 1]) != s.end())
                {
                    if (s[ps[j] - ps[i - 1]] > 0)
                    {
                        ans += s[ps[j] - ps[i - 1]];
                        s[ps[j] - ps[i - 1]] = 0;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
