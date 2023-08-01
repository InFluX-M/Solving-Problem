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
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<int, int> s;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            s[t]++;
        }

        vector<int> res;
        int l = 0, r = 0;

        for (pii u : s)
        {
            res.push_back(u.second);
            r += u.second;
        }
        sort(all(res));

        vector<ll> ps(res.size());
        ps[0] = res[0];

        for (int i = 1; i < res.size(); i++)
            ps[i] = ps[i - 1] + res[i];

        int finaly = INT_MAX;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            int price = INT_MAX;
            for (int i = 0; i < res.size(); i++)
            {
                int tmp = 0;
                int u = lower_bound(all(res), res[i]) - res.begin();
                if (u > 0)
                {
                    tmp += ps[u - 1];
                }

                int total = ps[res.size() - 1] - ps[i];
                tmp += (total - (res.size() - i - 1) * res[i]);

                price = min(price, tmp);
            }

            if (price <= mid)
            {
                finaly = min(finaly, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << finaly << '\n';
    }
    return 0;
}
