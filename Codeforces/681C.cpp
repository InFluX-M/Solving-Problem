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
    cin.ignore();

    vector<string> s(n);
    for (int i = 0; i < n; i++)
        getline(cin, s[i]);

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    vector<string> res;
    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == 'i')
        {
            ll t = stoll(s[i].substr(s[i].find(" ") + 1));
            pq.push(t);
        }
        else if (s[i][0] == 'r')
        {
            if (pq.empty())
            {
                res.push_back("insert " + to_string(0));
                pq.push(0);
            }

            pq.pop();
        }
        else
        {
            ll t = stoll(s[i].substr(s[i].find(" ") + 1));
            while (!pq.empty() && pq.top() < t)
            {
                res.push_back("removeMin");
                pq.pop();
            }
            if (pq.top() != t || pq.empty())
            {
                pq.push(t);
                res.push_back("insert " + to_string(t));
            }
        }
        res.push_back(s[i]);
    }

    cout << res.size() << '\n';
    for (string p : res)
        cout << p << '\n';
    
    return 0;
}
