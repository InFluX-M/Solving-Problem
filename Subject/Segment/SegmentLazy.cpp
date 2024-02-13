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
    ll ans;

public:
    Data(ll ans_)
    {
        ans = ans_;
    }

    Data()
    {
        ans = 0;
    }
};

struct Lazy
{
    ll add = 0;

public:
    Lazy(ll add_)
    {
        add = add_;
    }

    Lazy() {}
};

#define lid (id << 1)
#define rid (lid + 1)
#define mid ((l + r) >> 1)
#define print(d) cout << d.ans << ' ' << d.pre << ' ' << d.suf << ' ' << d.sum << ' ' << endl;

const int mxn = 1e6 + 5;
int n, q;
ll a[mxn];
Data seg[mxn << 2];
Lazy lazy[mxn << 2];

Data merge(Data l, Data r)
{
    return Data(l.ans + r.ans);
}

void build(int l = 0, int r = n, int id = 1)
{
    if (l + 1 == r)
    {
        seg[id] = Data(a[l]);
        return;
    }

    build(l, mid, lid);
    build(mid, r, rid);

    seg[id] = merge(seg[lid], seg[rid]);
}

void relax(int l, int r, int id)
{
    ll x = lazy[id].add;

    seg[lid].ans += x * (mid - l);
    seg[rid].ans += x * (r - mid);

    lazy[lid].add += x;
    lazy[rid].add += x;

    lazy[id] = 0;
}

void relax2(int id, Lazy x, int l)
{
    seg[id].ans += x.add * l;
    lazy[id].add += x.add;
}
void relaxT(int l, int r, int id)
{
    relax2(lid, lazy[id], mid - l);
    relax2(rid, lazy[id], r - mid);
    lazy[id].add = 0;
}

void upd(int s, int t, ll x, int l = 0, int r = n, int id = 1)
{
    if (l >= s && r <= t)
    {
        relax2(id, Lazy(x), r - l);
        return;
    }

    relaxT(l, r, id);

    int md = mid;

    if (t <= md)
        return upd(s, t, x, l, mid, lid);

    if (s >= md)
        return upd(s, t, x, mid, r, rid);

    upd(s, t, x, l, mid, lid);
    upd(s, t, x, mid, r, rid);
    return;
}

Data get(int s, int t, int l = 0, int r = n, int id = 1)
{
    if (l >= s && r <= t)
        return seg[id];

    relaxT(l, r, id);

    if (t <= mid)
        return get(s, t, l, mid, lid);

    if (s >= mid)
        return get(s, t, mid, r, rid);

    return merge(get(s, t, l, mid, lid), get(s, t, mid, r, rid));
}

void solve()
{
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build();

    while (q--)
    {
        int t;
        cin >> t;

        int l, r;
        cin >> l >> r;
        l--;

        if (t == 1)
        {
            ll p;
            cin >> p;

            upd(l, r, p);
        }
        else
        {
            cout << get(l, r).ans << endl;
        }
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
