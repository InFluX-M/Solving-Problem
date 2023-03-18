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
    int n, k, q;
    cin >> n >> k >> q;

    vector<set<int>> cls(k, set<int>());
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;

        while (t--)
        {
            int u;
            cin >> u;
            cls[i].insert(u);
        }
    }

    while (q--)
    {
        int t;
        cin >> t;
        map<int, int> o;
        int aim = t;

        while (t--)
        {
            int p;
            cin >> p;

            for (int y : cls[p - 1])
                o[y]++;
        }

        int cnt = 0;
        for (pair<int, int> y : o)
        {
            if (y.second == aim)
                cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}
