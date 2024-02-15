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
    int n;
    cin >> n;

    vi s(n);
    for (size_t i = 0; i < n; i++)
        cin >> s[i];

    int q;
    cin >> q;

    stack<pii> st;
    while (q--)
    {
        int c;
        cin >> c;

        if (c == 1)
        {
            int p, x;
            cin >> p >> x;
            st.push({p - 1, x});
        }
        else
        {
            int x;
            cin >> x;
            st.push({-1, x});
        }
    }

    int base = INT_MIN;
    vi val(n, INT_MIN);
    while (!st.empty())
    {
        pii temp = st.top();
        st.pop();

        if (temp.first == -1)
            base = max(base, temp.second);
        else
            val[temp.first] = max(temp.second, base);
    }
    
    for (int i = 0; i < n; i++)
        if (val[i] == INT_MIN)
            val[i] = max(s[i], base);

    for (int i = 0; i < n; i++)
        cout << val[i] << " ";

    return 0;
}
