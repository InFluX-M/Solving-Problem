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
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (n == 1)
        {
            if (a[0] % 2 == 0)
                cout << "NO";
            else
                cout << "YES";

            cout << '\n';
            continue;
        }

        int flag[n];
        fill_n(flag, n, 0);

        int nEven = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && flag[i - 1] != 2 && a[i] % 2 == 0)
            {
                nEven++;
                flag[i] = 2;
            }
        }

        int nOdd = 0;
        for (int i = 0; i < n; i++)
        {
            if (n > 1 && i == 0 && flag[i + 1] != 2)
            {
                nOdd++;
                flag[i] = 2;
            }
            else if (n > 1 && i == n - 1 && flag[i - 1] != 2)
            {
                nOdd++;
                flag[i] = 2;
            }
            else if (flag[i - 1] != 2 && flag[i + 1] != 2)
            {
                nOdd++;
                flag[i] = 2;
            }
        }

        if (nOdd <= 0)
            cout << "NO";
        else if (x <= nOdd + nEven)
            cout << "YES";
        else
            cout << "NO";

        cout << '\n';
    }

    return 0;
}
