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
    vector<str> t;
    t.push_back(":)");
    t.push_back(";)");
    t.push_back(":-)");
    t.push_back(";-)");

    str s;
    cin >> s;

    int res = 0;

    int i = 0;
    while (true)
    {
        int j1 = s.find(t[0], i);
        int j2 = s.find(t[1], i);
        int j3 = s.find(t[2], i);
        int j4 = s.find(t[3], i);

        int idx = s.length() + 1;
        if (j1 != -1)
            idx = min(idx, j1);
        if (j2 != -1)
            idx = min(idx, j2);
        if (j3 != -1)
            idx = min(idx, j3);
        if (j4 != -1)
            idx = min(idx, j4);

        if (idx == s.length() + 1)
            break;
        if (s.empty())
            break;
        if ((j1 == j2) && (j2 == j3) && (j3 == j4) && (j4 == -1))
            break;

        cout << idx << "\n";
        i = idx + 1;
    }

    return 0;
}
