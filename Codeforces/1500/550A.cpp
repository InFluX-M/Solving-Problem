#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vector_ll;
typedef vector<string> vector_string;
typedef vector<char> vector_char;
typedef vector<bool> vector_bool;
typedef vector<int> vector_int;

#define find_vec(vec, item, first_index, last_index) find(vec.begin() + first_index, vec.begin() + last_index + 1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin() + first_index, vec.begin() + last_index + 1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin() + first_index, vec.begin() + last_index + 1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin() + first_index, vec.begin() + last_index + 1, 0)

ll mod = (ll)(1e9 + 7);

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
    string s;
    cin >> s;

    int n = s.length();
    int st = 0;
    int aba = 0;
    string s1 = "";
    bool fg = false;

    int i = 0;
    for (i = 0; i < n - 2; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A')
        {
            aba++;
            i += 2;
        }
        else if (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B')
        {
            aba++;
            i += 2;
        }
        else
            s1.push_back(s[i]);
    }

    if (i != n && i != n - 1)
    {
        s1.push_back(s[n - 2]);
        s1.push_back(s[n - 1]);
    }

    s = s1;
    if (aba > 1)
    {
        cout << "YES";
        return 0;
    }

    for (int i = 0; s.length() > 0 && i < s.length() - 1; i++)
    {
        if (st == 0)
        {
            if (s[i] == 'A' && s[i + 1] == 'B')
            {
                st = 1;
                i++;
            }
            else if (s[i] == 'B' && s[i + 1] == 'A')
            {
                st = 2;
                i++;
            }
        }
        else if (st == 1)
        {
            if (s[i] == 'B' && s[i + 1] == 'A')
            {
                cout << "YES";
                return 0;
            }
        }
        else if (st == 2)
        {
            if (s[i] == 'A' && s[i + 1] == 'B')
            {
                cout << "YES";
                return 0;
            }
        }
    }

    if ((st == 1 || st == 2) && aba >= 1)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
