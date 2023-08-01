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
    int n, k;
    cin >> n >> k;

    vi s(n);
    ll r = 0, l = 1000000000000000;
    for (size_t i = 0; i < n; i++)
    {
        cin >> s[i];
        if (l > s[i])
            l = s[i];
        r = r + s[i];
    }

    if (k == 1)
        cout << r;
    else if (k == n)
        cout << *max_element(all(s));
    else
    {
        ll res = 1000000000000000;

        while (l <= r)
        {
            ll mid = (l + r) / 2;

            bool valid = true;
            ll cnt = 0, temp = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] > mid)
                {
                    valid = false;
                    break;
                }
                if (temp + s[i] >= mid)
                {
                    cnt++;
                    temp = (temp + s[i] == mid) ? 0 : s[i];
                }
                else
                    temp += s[i];
            }
            cnt += (temp != 0);
            valid = valid & (cnt <= k);

            if (valid)
            {
                res = min(res, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << res;
    }

    return 0;
}
