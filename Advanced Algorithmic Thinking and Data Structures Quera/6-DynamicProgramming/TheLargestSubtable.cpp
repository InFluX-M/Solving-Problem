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
    int n, m;
    cin >> n >> m;

    ll a[n][m];
    ll sm[n][m];
    ll dp[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
    {
        sm[i][0] = a[i][0];
        for (int j = 1; j < m; j++)
        {
            sm[i][j] = sm[i][j - 1] + a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        dp[0][i] = sm[0][i];
        for (int j = 1; j < n; j++)
        {
            dp[j][i] = dp[j - 1][i] + sm[j][i];
        }
    }

    ll mxAim = dp[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ll mxEach = dp[i][0];
            for (int k = 0; k < m; k++)
            {
                if (i == 0)
                    mxEach = max(mxEach, dp[j][k]);
                else
                    mxEach = max(mxEach, dp[j][k] - dp[i][k]);
            }

            mxAim = max(mxAim, mxEach);
        }
    }

    cout << mxAim << "\n";

    return 0;
}
