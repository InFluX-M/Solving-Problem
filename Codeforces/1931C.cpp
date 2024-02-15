#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

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
#define lb lower_bound
#define ub upper_bound
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

const int mxn = 3e5 + 4;

void solve()
{
    int n;
    cin >> n;

    vl s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int cnt = 0;
    if (s[0] == s[n - 1])
    {
        int i = 0, j = n - 1;
        while (i < n && s[i] == s[0])
            i++, cnt++;
        while (j >= i && s[j] == s[n - 1])
            j--, cnt++;
    }
    else
    {
        int cnt1 = 0, cnt2 = 0;
        int i = 0, j = n - 1;
        while (i < n && s[i] == s[0])
            i++, cnt1++;
        while (j >= i && s[j] == s[n - 1])
            j--, cnt2++;
        cnt = max(cnt1, cnt2);
    }

    cout << n - cnt << '\n';
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
