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

std::vector<std::string> split(std::string s, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void solve()
{
    int n;
    cin >> n;

    cin.ignore();

    stack<string> st;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        if (s == "pwd")
        {
            vector<string> res;
            stack<string> tmp = st;
            while (!tmp.empty())
            {
                res.pb(tmp.top());
                tmp.pop();
            }
            reverse(all(res));
            cout << '/';

            for (string c : res)
                cout << c << '/';

            cout << nl;
            continue;
        }

        int j = 0;
        vector<str> path = split(s.substr(3), "/");
        if (path[0].empty())
        {
            while (!st.empty())
            {
                st.pop();
            }
            j++;
        }
        for (; j < sz(path); j++)
        {
            if (path[j] == "..")
            {
                st.pop();
            }
            else
                st.push(path[j]);
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
