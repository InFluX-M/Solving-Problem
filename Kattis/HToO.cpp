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

bool isAlph(char c)
{
    return (c >= 'A' && c <= 'Z');
}

pair<int, int> solve(string s, int j)
{
    string temp = "";
    int i = j;
    while (i < s.length() && !isAlph(s[i]))
    {
        temp.push_back(s[i]);
        i++;
    }

    return make_pair(stoi(temp), i);
}

unordered_map<char, int> st(string s, int k)
{
    unordered_map<char, int> inp;
    for (int i = 0; i < s.length(); i++)
    {
        if (i == s.length() - 1)
        {
            inp[s[i]] += k;
        }
        else if (isAlph(s[i]) && isAlph(s[i + 1]))
        {
            inp[s[i]] += k;
        }
        else
        {
            pair<int, int> t = solve(s, i + 1);
            inp[s[i]] += t.first * k;
            i = t.second - 1;
        }
    }

    return inp;
}

int main()
{
    fastio;

    string s, aim;
    int k;
    cin >> s >> k >> aim;

    unordered_map<char, int> inp = st(s, k);
    unordered_map<char, int> out = st(aim, 1);

    int res = 0;
    bool fg = false;
    for (pair<char, int> t : out)
    {
        if (inp.find(t.first) == inp.end())
        {
            res = 0;
            break;
        }
        else
        {
            if(!fg) 
            {
                res = inp[t.first] / t.second;
                fg = true;
            }
            else res = min(res, inp[t.first] / t.second);
        }
    }

    cout << res;

    return 0;
}
