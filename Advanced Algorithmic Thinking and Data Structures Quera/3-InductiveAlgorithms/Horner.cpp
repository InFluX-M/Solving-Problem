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

ll mul_mod(ll a, ll b)
{
    return (a % mod) * (b % mod) % mod;
}
ll min_mod(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}
ll sum_mod(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    int n, x;
    cin >> n >> x;

    ll a[n + 1], sum;
    for (int i = 0; i < n + 1; i++)
        cin >> a[i];

    sum = 0;
    for (int i = 0; i < n+1; i++)
    {
        sum = (sum*x + a[i]) % mod;
    }

    cout << sum % mod;
    return 0;
}