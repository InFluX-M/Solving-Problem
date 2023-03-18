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

int main()
{
	int n;
	cin >> n;

	ll dp[n];
	ll a[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = 0;
		cin >> a[i];
	}

	dp[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1] + a[i] > a[i])
			dp[i] = dp[i - 1] + a[i];
		else
			dp[i] = a[i];
	}

	ll mx = *max_element(dp, dp + n);

	cout << mx;
}
