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
#define nl "\n"
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
void least(int n, int s)
{
    vector<int> num(n, 0);
    int i = n - 1;
    for (; i >= 0; i--)
    {
        if (s > 9)
        {
            s -= 9;
            num[i] = 9;
        }
        else
            break;
    }

    if (i > 0 && s > 1)
    {
        num[i] = s - 1;
        s = 1;
        i--;
    }
    num[0] = s;

    for (int i = 0; i < n; i++)
        cout << num[i];

    cout << ' ';
}

void great(int n, int s)
{
    vector<int> num(n, 0);
    int i = 0;
    for (; i < n; i++)
    {
        if (s >= 9)
        {
            s -= 9;
            num[i] = 9;
        }
        else
        {
            break;
        }
    }

    num[i] = s;

    for (int i = 0; i < n; i++)
        cout << num[i];
}

void solve()
{
    int n, s;
    cin >> n >> s;

    if (s == 0 && n == 1)
    {
        cout << 0 << ' ' << 0;
    }
    else if (s < 1 || s > 9 * n)
        cout << -1 << ' ' << -1;
    else
    {
        least(n, s);
        great(n, s);
    }
}

int32_t main()
{
    int t = 1;
    while (t--)
        solve();

    return 0;
}
