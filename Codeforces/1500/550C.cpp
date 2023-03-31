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

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

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

int main()
{
    unordered_set<string> ans;
    for (int i = 2; i <= 12; i++)
        ans.insert(to_string(i * 8));

    fastio;

    string s;
    cin >> s;

    if (find(s.begin(), s.end(), '0') != s.end())
    {
        cout << "YES\n"
             << 0;
        return 0;
    }
    else if (find(s.begin(), s.end(), '8') != s.end())
    {
        cout << "YES\n"
             << 8;
        return 0;
    }
    else if (s.length() == 1)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        for (int i = 0; i < s.size() - 1; i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                string temp = "";
                temp += s[i];
                temp += s[j];
                if (ans.find(temp) != ans.end())
                {
                    cout << "YES\n"
                         << temp;
                    return 0;
                }
            }
        }

        for (int i = 0; i < s.size() - 2; i++)
        {
            for (int j = i + 1; j < s.size() - 1; j++)
            {
                string temp = "";
                temp += s[i];
                temp += s[j];
                if (ans.find(temp) != ans.end())
                {
                    cout << "YES\n"
                         << temp;
                    return 0;
                }

                for (int k = j + 1; k < s.size(); k++)
                {
                    int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                    if (num % 8 == 0)
                    {
                        cout << "YES\n"
                             << num;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NO";
    return 0;
}
