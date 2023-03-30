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
    map<char, int> m;
    m['a'] = 2;
    m['b'] = 22;
    m['c'] = 222;
    m['d'] = 3;
    m['e'] = 33;
    m['f'] = 333;
    m['g'] = 4;
    m['h'] = 44;
    m['i'] = 444;
    m['j'] = 5;
    m['k'] = 55;
    m['l'] = 555;
    m['m'] = 6;
    m['n'] = 66;
    m['o'] = 666;
    m['p'] = 7;
    m['q'] = 77;
    m['r'] = 777;
    m['s'] = 7777;
    m['t'] = 8;
    m['u'] = 88;
    m['v'] = 888;
    m['w'] = 9;
    m['x'] = 99;
    m['y'] = 999;
    m['z'] = 9999;
    m[' '] = 0;

    int t;
    cin >> t;
    int f = t;
    cin.ignore();

    while (t--)
    {
        string s;
        getline(cin, s);

        string aim = to_string(m[s[0]]);
        for (int i = 1; i < s.length(); i++)
        {
            if (aim[aim.length() - 1] == to_string(m[s[i]]).front())
                aim += " ";
            aim += to_string(m[s[i]]);
        }

        cout << "Case "
             << "#" << (f - t) << ": " << aim << "\n";
    }

    return 0;
}
