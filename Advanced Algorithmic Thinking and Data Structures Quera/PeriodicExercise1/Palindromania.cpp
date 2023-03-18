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

int k = 0;
void solve(string s, int idx)
{
    if (idx == s.size())
    {
        k++;
        return;
    }

    if (idx != s.size()-1 && s[idx] == '?')
    {
        if (idx == 0)
        {
            s[idx] = 'a';
            solve(s, idx + 1);
            s[idx] = 'b';
            solve(s, idx + 1);
        }
        else if (idx == 1)
        {
            s[idx] = 'a';
            solve(s, idx + 1);
            s[idx] = 'b';
            solve(s, idx + 1);
        }
        else if (s[idx - 2] == 'a' && s[idx - 1] == 'a')
        {
            s[idx] = 'b';
            if (s[idx - 1] == 'a' && s[idx + 1] == 'a')
                return;

            solve(s, idx + 1);
        }
        else if (s[idx - 2] == 'a' && s[idx - 1] == 'b')
        {
            s[idx] = 'b';
            if (s[idx - 1] == 'b' && s[idx + 1] == 'b')
                return;

            solve(s, idx + 1);
        }
        else if (s[idx - 2] == 'b' && s[idx - 1] == 'a')
        {
            s[idx] = 'a';
            if (s[idx - 1] == 'a' && s[idx + 1] == 'a')
                return;
            solve(s, idx + 1);
        }
        else if (s[idx - 2] == 'b' && s[idx - 1] == 'b')
        {
            s[idx] = 'a';
            if (s[idx - 1] == 'b' && s[idx + 1] == 'b')
                return;
            solve(s, idx + 1);
        }
    }
    else if (idx != 0 && idx != s.size() - 1 && s[idx] == 'b')
    {
        if (s[idx - 1] == 'b' && s[idx + 1] == 'b')
            return;

        if (s[idx - 1] == 'a' && s[idx + 1] == 'a')
            return;
    }
    else if (idx != 0 && idx != s.size() - 1)
    {
        if (s[idx - 1] == 'b' && s[idx + 1] == 'b')
            return;

        if (s[idx - 1] == 'a' && s[idx + 1] == 'a')
            return;
    }
    else if(idx == s.size()-1)
    {
        if(s[idx] == '?')
        {
            
        }
        else if(s[idx] == 'a')
        {
            
        }
        else if(s[idx] == 'b')
        {

        }
    }
}

int main()
{
    string s;
    cin >> s;

    solve(s, 0);

    cout << k;
    return 0;
}
