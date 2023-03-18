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
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    char c = s[0];
    int idx = 1;

    while (idx < n && s[idx] == c)
    {
        idx++;
    }

    if (idx == n || idx == n - 1)
    {
        cout << 0;
        return 0;
    }

    int idx2 = idx;
    int cnt2 = 0;
    bool flg = false;

    if (s[n - 1] == c)
    {
        while (s[idx2] != c)
        {
            cnt2++;
            idx2++;
        }

        while (idx2 < n && s[idx2] == c)
        {
            idx2++;
        }

        if (idx2 == n)
            flg = true;
    }

    for (int i = idx + 1; i < n; i++)
    {
        if (s[i] == c)
            cnt++;
    }

    if (flg)
        cout << min(cnt2, min(cnt, n - 1 - cnt));
    else
        cout << min(cnt, n - 1 - cnt);

    return 0;
}
