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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt = 0;

    if (k == 2)
    {
        char s1 = s[0];

        int idx = 1;
        while (idx < n && s[idx] == s1)
        {
            idx++;
        }
        char s2 = s[idx];

        int s11 = 0, s12 = 0, s21 = 0, s22 = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == s1)
                    s11++;
                else
                    s21++;
            }
            else
            {
                if (s[i] == s1)
                    s12++;
                else
                    s22++;
            }
        }
        cout << min(s11 + s22, s12 + s21) << "\n";
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (i > 0 && s[i] == s[i - 1] && s[i] == s[i + 1])
            {
                s[i] = ' ';
                cnt++;
            }
            else if (s[i] == s[i + 1])
            {
                if (i < n - 2 && s[i + 1] == s[i + 2])
                    continue;
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}
