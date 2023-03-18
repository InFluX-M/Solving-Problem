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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int aim = 0;

    int mx1 = a[0], mx2 = a[0], aim = 1;
    for (int i = 0; i < n; i++)
    {
        int mx1 = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if(a[j] > mx2 || a[j] > mx1) 
            {
                
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int mn = min(a[i], a[j]);
    //         bool flag = true;
    //         int len = 2;
    //         for (int k = i + 1; k < j; k++)
    //         {
    //             if (a[k] >= mn)
    //             {
    //                 flag = false;
    //                 break;
    //             }
    //             len++;
    //         }

    //         if (flag)
    //         {
    //             aim = max(aim, len);
    //             if (len == n)
    //             {
    //                 cout << len;
    //                 return 0;
    //             }
    //         }
    //     }
    // }

    cout << aim;
    return 0;
}
