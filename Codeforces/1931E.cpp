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
    multiset<pair<int, int>, greater<pair<int, int>>> pqq;
    multiset<pair<int, int>> pqqq;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int cnt = 0;
        string p = s;
        while (p.back() == '0')
        {
            cnt++;
            p.pop_back();
        }
        pqq.insert({cnt, s.length()});
        pqqq.insert({cnt, s.length()});
    }

    bool turn = true;

    while ((turn && sz(pqq) > 0) || (!turn && sz(pqq) > 1))
    {
        pair<int, int> u = *pqq.begin();
        pqq.erase(pqq.find(u));
        pqqq.erase(pqqq.find(u));

        if (turn)
        {
            pqq.insert({0, u.S - u.F});
            pqqq.insert({0, u.S - u.F});
        }
        else
        {
            pair<int, int> v = *pqqq.begin();
            pqq.erase(pqq.find(v));
            pqqq.erase(pqqq.find(v));

            pqq.insert({v.F, u.S + v.S});
            pqqq.insert({v.F, u.S + v.S});
        }

        turn = !turn;
    }

    if ((*pqq.begin()).S > m)
        cout << "Sasha";
    else
        cout << "Anna";

    cout << nl;
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
