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
    fastio int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int aim = 0;

        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                string p = "";
                bool flg = false;
                for (int k = 0; k < s.length(); k++)
                {
                    if (s[k] - '0' == i && !flg)
                    {
                        p += to_string(i);
                        flg = true;
                    }
                    else if (s[k] - '0' == j && flg)
                    {
                        p += to_string(j);
                        flg = false;
                    }
                }
                if (p.empty())
                    continue;
                if (p.length() == 1)
                    aim = max(aim, 1);
                else if (p.length() % 2 == 1)
                {
                    aim = max(aim, (int)p.length() - (p[0] != p[1]));
                }
                else
                {
                    aim = max(aim, (int)p.length());
                }
            }
        }

        cout << s.length() - aim << endl;
    }

    return 0;
}
