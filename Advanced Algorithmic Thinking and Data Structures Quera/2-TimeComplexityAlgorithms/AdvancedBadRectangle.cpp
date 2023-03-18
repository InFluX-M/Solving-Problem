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

#define ll long long int
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

    ll nO = 0;
    for (ll i = 1; i <= floor(n / 3.0); i++)
    {
        int temp = (floor(n / 2.0) - (2 * i) + 1);
        ll lower = max(0, temp);
        ll upper = (floor((n - 3.0 * i) / 2.0));

        nO += (upper - lower + 1);
    }

    cout << nO % (1000000000 + 7);
}

// int main()
// {
// 	ll n;
// 	cin >> n;

// 	ll nT = 0;
// 	for (int i = 1; i < n; i++)
// 	{
// 		int t = n / 2 - 2 * i + 1;
// 		ll lower = max(0, t);
// 		ll upper = (n - 3 * i) / 2;
// 		nT = sum(nT, upper - lower + 1);
// 	}

// 	cout << nT;
// }