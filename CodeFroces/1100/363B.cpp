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

    vector_int h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int sums[n];
    sums[0] = h[0];
    for (int i = 1; i < n; i++)
        sums[i] = sums[i - 1] + h[i];

    int ans = sums[k - 1];
    int ix = 0;

    for (int i = 1; i < n - k; i++)
        if (ans > sums[i + k - 1] - sums[i - 1])
        {
            ans = sums[i + k - 1] - sums[i - 1];
            ix = i;
        }

    cout << ix + 1;
    return 0;
}
