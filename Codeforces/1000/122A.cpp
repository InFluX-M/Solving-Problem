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

bool valid(string s)
{
    for(int i=0; i<s.length(); i++)
        if(s[i] != '7' && s[i] != '4')
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;

    if(valid(to_string(n)))
    {
        cout << "YES";
        return 0;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
        {
            if(valid(to_string(i)))
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}
