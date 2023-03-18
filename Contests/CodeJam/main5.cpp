#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vector_ll;
typedef vector<string> vector_string;
typedef vector<char> vector_char;
typedef vector<bool> vector_bool;
typedef vector<int> vector_int;

ll mod = (ll)(1e9 + 7);

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

const int maxn = 1000 + 10;

int main()
{
    ll c[maxn][maxn];

    for (int i = 0; i < maxn; i++)
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }

    ll f[maxn];

    for (int i = 0; i < maxn; i++)
        if (i == 0 || i == 1)
            f[i] = 1;
        else
            f[i] = (f[i - 1] * i) % mod;

    int n;
    cin >> n;

    unordered_set<int> fail;
    unordered_set<int> a;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        if (t)
            a.insert(t);
        else
            fail.insert(i + 1);
    }

    unordered_set<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (a.find(i) == a.end())
            s.insert(i);
    }

    int cnt = 0;
    for (int t : fail)
    {
        if (s.find(t) != s.end())
            cnt++;
    }

    if (fail.size() == 0)
        cout << 0;
    else
    {
        ll aim = f[fail.size()];
        for (int i = 1; i <= cnt; i++)
        {
            ll t1 = c[cnt][i];
            ll t2 = f[fail.size() - i];
            aim = ll((aim + pow(-1, i) * mul(t1, t2))) % mod;
        }

        cout << aim % mod;
    }

    return 0;
}
