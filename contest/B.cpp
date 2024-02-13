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

int n = 0;
int res = 0;

void bt(vector<pii> q)
{
    res = min(res, sz(q));

    if (sz(q) == 1)
        return;

    for (int i = 0; i < sz(q); i++)
    {
        for (int j = 0; j < sz(q); j++)
        {
            if (i == j)
                continue;

            if (q[i].first == q[j].first && abs(q[i].second - q[j].second) == 1)
            {
                if (q[i].second - q[j].second == 1)
                    q.push_back({q[i].first, q[j].second - 1});
                else
                    q.push_back({q[i].first, q[j].second + 1});

                pii t1 = q[i];
                pii t2 = q[j];
                q.erase(q.begin() + i - 1);
                q.erase(q.begin() + j - 1);

                bt(q);

                q.pop_back();
                q.insert(q.begin() + i - 1, t1);
                q.insert(q.begin() + j - 1, t2);
            }
            if (q[i].second == q[j].second && abs(q[i].first - q[j].first) == 1)
            {
                pii t3;
                if (q[i].first - q[j].first == 1)
                {
                    q.push_back({q[j].first - 1, q[j].second});
                }
                else
                {
                    q.push_back({q[j].first + 1, q[j].second});
                }

                pii t1 = q[i];
                pii t2 = q[j];
                q.erase(q.begin() + i - 1);
                q.erase(q.begin() + j - 1);

                bt(q);

                q.pop_back();
                q.insert(q.begin() + i - 1, t1);
                q.insert(q.begin() + j - 1, t2);
            }
        }
    }
}

void solve()
{
    vector<pii> s;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char c;
            cin >> c;

            if (c == 'o')
            {
                s.pb({i, j});
                n++;
                res++;
            }
        }
    }

    bt(s);

    cout << res << ' ' << n - res << endl;
    n = 0;
    res = 0;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
