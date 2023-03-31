#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll mod = 1e9 + 7;

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2")

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

ll mul(ll a, ll b)
{
    return (a % mod) * (b % mod) % mod;
}

ll min(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll sum(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

vector<string> nums;
vector<string> a;

void solve(int i, int n, string s, unordered_set<string> &aim)
{
    if (i == n - 1)
    {
        aim.insert(s + nums[i]);
        return;
    }

    solve(i + 1, n, s + nums[i] + '.', aim);
    solve(i + 1, n, s + nums[i] + '+', aim);
}

int main()
{
    fastio;

    string s;
    cin >> s;

    string temp = "";

    for (char c : s)
    {
        if (c == '+')
        {
            nums.push_back(temp);
            temp = "";
        }
        else
            temp.push_back(c);
    }
    nums.push_back(temp);

    unordered_set<string> aim;
    solve(0, nums.size(), "", aim);

    unordered_set<string> res;
    for (string t : aim)
    {
        stack<char> s1;
        stack<string> s2;

        string newS = "";
        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] != '.')
                newS.push_back(s[i]);
        }

        string finaly = newS.substr(0, newS.find('+'));
        if (finaly == newS)
        {
            res.insert(finaly);
            continue;
        }

        string temp = "";

        bool flag = false;
        for (int i = finaly.length() + 1; i < newS.length(); i++)
        {
            if (newS[i] == '+')
            {
                finaly = to_string(stoll(finaly) + stoll(temp));
                temp = "";
            }
            else
                temp.push_back(newS[i]);
        }
        finaly = to_string(stoll(finaly) + stoll(temp));

        res.insert(finaly);
    }
    cout << res.size();

    return 0;
}
