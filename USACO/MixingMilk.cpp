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
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    fastio;
    array<pii, 3> s;
    for (int i = 0; i < 3; i++)
        cin >> s[i].first >> s[i].second;

    for (int i = 0; i < 100; i++)
    {
        int mx = s[i % 3].second;
        int mxC = s[(i + 1) % 3].first - s[(i + 1) % 3].second;

        s[i % 3].second = mx - min(mxC, mx);
        s[(i + 1) % 3].second += min(mxC, mx);
    }

    for (int i = 0; i < 3; i++)
        cout << s[i].second << '\n';
    return 0;
}
