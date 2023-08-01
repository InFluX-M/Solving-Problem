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

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int c[m];
    fill_n(c, m, 0);
    c[0] = 1;

    int k = 0, l = 1;
    while (l < m)
    {
        if (b[l] == b[l - 1])
            c[k]++;
        else
        {
            k++;
            c[k] = 1;
        }
        l++;
    }

    int i = 0, j = 0, q = 0;
    int res = 0;

    while (j < m)
    {
        int cnt = 0;

        while (i < n && b[j] >= a[i])
        {
            if (b[j] == a[i])
                cnt++;

            i++;
        }

        res += (c[q] * cnt);
        j += c[q];
        q++;
    }

    cout << res;

    return 0;
}
