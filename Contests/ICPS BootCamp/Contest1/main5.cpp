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

    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int aim = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int nLE = 0;
            int c = a[i][j];
            if (i == 0 && j == 0)
            {
                nLE += (c <= a[i][j + 1]);
                nLE += (c <= a[i + 1][j]);

                if (nLE == 2)
                    aim++;
            }
            else if (i == 0 && j == n - 1)
            {
                nLE += (c <= a[i][j - 1]);
                nLE += (c <= a[i + 1][j]);
                if (nLE == 2)
                    aim++;
            }
            else if (i == n - 1 && j == 0)
            {
                nLE += (c <= a[i][j + 1]);
                nLE += (c <= a[i - 1][j]);
                if (nLE == 2)
                    aim++;
            }
            else if (i == n - 1 && j == n - 1)
            {
                nLE += (c <= a[i - 1][j]);
                nLE += (c <= a[i][j - 1]);
                if (nLE == 2)
                    aim++;
            }
            else if (i == 0)
            {
                nLE += (c <= a[i][j - 1]);
                nLE += (c <= a[i][j + 1]);
                nLE += (c <= a[i + 1][j]);
                if (nLE == 3)
                    aim++;
            }
            else if (j == 0)
            {
                nLE += (c <= a[i + 1][j]);
                nLE += (c <= a[i][j + 1]);
                nLE += (c <= a[i - 1][j]);
                if (nLE == 3)
                    aim++;
            }
            else if (i == n - 1)
            {
                nLE += (c <= a[i][j - 1]);
                nLE += (c <= a[i][j + 1]);
                nLE += (c <= a[i - 1][j]);
                if (nLE == 3)
                    aim++;
            }
            else if (j == n - 1)
            {
                nLE += (c <= a[i + 1][j]);
                nLE += (c <= a[i][j - 1]);
                nLE += (c <= a[i - 1][j]);
                if (nLE == 3)
                    aim++;
            }
            else
            {
                nLE += (c <= a[i + 1][j]);
                nLE += (c <= a[i - 1][j]);
                nLE += (c <= a[i][j - 1]);
                nLE += (c <= a[i][j + 1]);

                if (nLE == 4)
                    aim++;
            }
        }
    }

    cout << aim;

    return 0;
}
