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
const int mxn = 1e6 + 5;
int n, q;
ll sum[mxn * 4];
ll mxprefix[mxn * 4];
ll mxsufix[mxn * 4];
ll mxsub[mxn * 4];
ll a[mxn];

void buildSum(int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        sum[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    buildSum(l, mid, id * 2);
    buildSum(mid, r, 2 * id + 1);

    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}

ll getSum(int s, int e, int l = 0, int r = n, int id = 1)
{
    if (s <= l && r <= e)
        return sum[id];

    if (e <= l || r <= s)
        return 0;

    int mid = (l + r) / 2;

    return getSum(s, e, l, mid, id * 2) + getSum(s, e, mid, r, id * 2 + 1);
}

void updSum(int p, int x, int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        sum[id] = x;
        return;
    }

    int mid = (l + r) / 2;

    if (p < mid)
        updSum(p, x, l, mid, id * 2);
    else
        updSum(p, x, mid, r, id * 2 + 1);

    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}

void buildMaxPrefix(int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        mxprefix[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    buildMaxPrefix(l, mid, id * 2);
    buildMaxPrefix(mid, r, 2 * id + 1);

    mxprefix[id] = max(mxprefix[id * 2], mxprefix[id * 2 + 1] + sum[id * 2]);
}

ll getMaxPrefix(int s, int e, int l = 0, int r = n, int id = 1)
{
    if (s <= l && r <= e)
        return mxprefix[id];

    if (e <= l || r <= s)
        return -1e18;

    int mid = (l + r) / 2;

    return max(getMaxPrefix(s, e, l, mid, id * 2), getMaxPrefix(s, e, mid, r, id * 2 + 1) + getSum(s, e, l, mid, id * 2));
}

void updMaxPrefix(int p, int x, int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        mxprefix[id] = x;
        return;
    }

    int mid = (l + r) / 2;

    if (p < mid)
        updMaxPrefix(p, x, l, mid, id * 2);
    else
        updMaxPrefix(p, x, mid, r, id * 2 + 1);

    mxprefix[id] = max(mxprefix[id * 2], mxprefix[id * 2 + 1] + sum[id * 2]);
}

void buildMaxSufix(int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        mxsufix[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    buildMaxSufix(l, mid, id * 2);
    buildMaxSufix(mid, r, 2 * id + 1);

    mxsufix[id] = max(mxsufix[id * 2 + 1], mxsufix[id * 2] + sum[id * 2 + 1]);
}

ll getMaxSufix(int s, int e, int l = 0, int r = n, int id = 1)
{
    if (s <= l && r <= e)
        return mxsufix[id];

    if (e <= l || r <= s)
        return -1e18;

    int mid = (l + r) / 2;

    return max(getMaxSufix(s, e, mid, r, id * 2 + 1), getMaxSufix(s, e, l, mid, id * 2) + getSum(s, e, mid, r, id * 2 + 1));
}

void updMaxSufix(int p, int x, int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        mxsufix[id] = x;
        return;
    }

    int mid = (l + r) / 2;

    if (p < mid)
        updMaxSufix(p, x, l, mid, id * 2);
    else
        updMaxSufix(p, x, mid, r, id * 2 + 1);

    mxsufix[id] = max(mxsufix[id * 2 + 1], mxsufix[id * 2] + sum[id * 2 + 1]);
}

void buildMaxSub(int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        mxsub[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    buildMaxSub(l, mid, id * 2);
    buildMaxSub(mid, r, 2 * id + 1);

    mxsub[id] = max(mxsub[id * 2], mxsub[id * 2 + 1]);
    mxsub[id] = max(mxsub[id], mxsufix[id * 2] + mxprefix[id * 2 + 1]);
}

ll getMaxSub(int s, int e, int l = 0, int r = n, int id = 1)
{
    if (s <= l && r <= e)
        return mxsub[id];

    if (e <= l || r <= s)
        return -1e18;

    int mid = (l + r) / 2;

    return max(max(getMaxSub(s, e, l, mid, id * 2), getMaxSub(s, e, mid, r, id * 2 + 1)), getMaxSufix(s, e, l, mid, id * 2) + getMaxPrefix(s, e, mid, r, id * 2 + 1));
}

void updMaxSub(int p, int x, int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        mxsub[id] = x;
        return;
    }

    int mid = (l + r) / 2;

    if (p < mid)
        updMaxSub(p, x, l, mid, id * 2);
    else
        updMaxSub(p, x, mid, r, id * 2 + 1);

    mxsub[id] = max(mxsub[id * 2], mxsub[id * 2 + 1]);
    mxsub[id] = max(mxsub[id], mxsufix[id * 2] + mxprefix[id * 2 + 1]);
}

void solve()
{
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    buildSum();
    buildMaxPrefix();
    buildMaxSufix();
    buildMaxSub();

    while (q--)
    {
        ll p, x;
        cin >> p >> x;
        p--;
        updSum(p, x);
        updMaxPrefix(p, x);
        updMaxSufix(p, x);
        updMaxSub(p, x);

        cout << max(0LL, getMaxSub(0, n)) << nl;
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}