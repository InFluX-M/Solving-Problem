#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;

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
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

ll modOp(ll a, ll b, int op)
{
    switch (op)
    {
    case 0:
        return ((a % MOD) + (b % MOD)) % MOD;
    case 1:
        return ((a % MOD) - (b % MOD) + MOD) % MOD;
    case 2:
        return (a % MOD) * (b % MOD) % MOD;
    }
}
bool *primes;
int main()
{
    fastio;

    primes = new bool[int(1e6) + 2];
    fill_n(primes, int(1e6 + 2), true);
    primes[1] = false;

    for (int i = 2; i < int(1e6) + 2; i++)
    {
        if (!primes[i])
            continue;
        for (int j = i + i; j < int(1e6) + 2; j += i)
        {
            primes[j] = false;
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        ll s = ll(sqrtl(x * 1.0));
        if (primes[s] && ll(sqrtl(x * 1.0)) * ll(sqrtl(x * 1.0)) == x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
