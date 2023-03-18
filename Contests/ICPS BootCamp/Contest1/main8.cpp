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
    bool a[13];

    cin >> a[1] >> a[2] >> a[3];
    cin >> b[10];
    cin >> a[4] >> a[5] >> a[6];
    cin >> b[11];
    cin >> a[7] >> a[8] >> a[9];
    cin >> b[12];
    cin >> a[0];

    vector<vector<pair<int, int>>> adj(100, vector<pair<int, int>>());

    for (int i = 0; i < 100; i++)
    {
        adj[i].push_back(make_pair(i, 0));
    }

    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i == j)
                continue;
            if (a[i])
            {
            }
            else
            {
            }

            adj[j].push_back(make_pair(i, 1));
        }
    }

    return 0;
}
