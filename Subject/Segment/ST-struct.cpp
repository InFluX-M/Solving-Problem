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

struct Data
{
    ll ans, pre, suf, sum;

public:
    Data(ll ans_, ll pre_, ll suf_, ll sum_)
    {
        ans = ans_;
        pre = pre_;
        suf = suf_;
        sum = sum_;
    }

    Data()
    {
        ans = 0;
        pre = 0;
        suf = 0;
        sum = 0;
    }
};

#define lid(id) (id << 1)
#define rid(id) (lid(id) + 1)
#define mid(l, r) ((l + r) >> 1)
#define print(d) cout << d.ans << ' ' << d.pre << ' ' << d.suf << ' ' << d.sum << ' ' << endl;

const int mxn = 1e6 + 5;
int n, q;
ll a[mxn];
Data seg[mxn << 2];

Data merge(Data l, Data r)
{
    Data tmp = Data(
        max({l.ans, r.ans, l.suf + r.pre}),
        max(l.pre, l.sum + r.pre),
        max(r.suf, r.sum + l.suf),
        l.sum + r.sum);

    return tmp;
}

void build(int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        seg[id] = Data(a[l], a[l], a[l], a[l]);
        return;
    }

    build(l, mid(l, r), lid(id));
    build(mid(l, r), r, rid(id));

    seg[id] = merge(seg[lid(id)], seg[rid(id)]);
}

void upd(int p, ll x, int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        seg[id] = Data(x, x, x, x);
        return;
    }

    if (p < mid(l, r))
        upd(p, x, l, mid(l, r), lid(id));
    else
        upd(p, x, mid(l, r), r, rid(id));

    seg[id] = merge(seg[lid(id)], seg[rid(id)]);
}

Data get(int s, int t, int l = 0, int r = n, int id = 1)
{
    if (l >= s && r <= t)
        return seg[id];

    if (t <= mid(l, r))
        return get(s, t, l, mid(l, r), lid(id));

    if (s >= mid(l, r))
        return get(s, t, mid(l, r), rid(id));

    return merge(get(s, t, l, mid(l, r), lid(id)), get(s, t, mid(l, r), rid(id)));
}

void solve()
{
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build();

    while (q--)
    {
        ll p, x;
        cin >> p >> x;
        p--;
        upd(p, x);

        cout << max(0LL, get(0, n).ans) << nl;
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
