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

int cnt = 0;
void solve(vector<int> a, bool same)
{
    if (a.size() == 1 || same)
    {
        cnt++;
        return;
    }

    cnt++;
    vector<int> t1, t2;
    bool same1 = true, same2 = true;
    int val1 = a[0], val2 = a[1];

    for (int i = 0; i < a.size(); i += 2)
    {
        if (val1 != a[i])
            same1 = false;
        t1.push_back(a[i]);
    }
    for (int i = 1; i < a.size(); i += 2)
    {
        if (val2 != a[i])
            same2 = false;
        t2.push_back(a[i]);
    }

    solve(t1, same1);
    solve(t2, same2);

    return;
}

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<int> a;
    int val1, same = true;

    for (int i = 0; i < pow(2, n); i++)
    {
        int t;
        cin >> t;
        if (i == 0)
            val1 = t;
        else if (val1 != t)
            same = false;
        a.push_back(t);
    }

    solve(a, same);

    cout << cnt;
    return 0;
}
