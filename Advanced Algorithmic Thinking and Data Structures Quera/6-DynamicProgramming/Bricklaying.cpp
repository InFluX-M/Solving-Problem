#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

typedef long long int ll;
typedef vector<ll> vector_ll;
typedef vector<string> vector_string;
typedef vector<char> vector_char;
typedef vector<bool> vector_bool;

#define find_vec(vec, item, first_index, last_index) find(vec.begin()+first_index, vec.begin()+last_index+1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin()+first_index, vec.begin()+last_index+1, 0)

ll dp[100000 + 1];

int main()
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= 100000; i++)
	{
		dp[i] = (dp[i - 1] % (1000000000 + 7) + dp[i - 2] % (1000000000 + 7) + dp[i - 3] % (1000000000 + 7) - dp[i - 4] % (1000000000 + 7) + (1000000000 + 7))% (1000000000 + 7) ;
	}

	ll q;
	cin >> q;

	while (q--)
	{
		ll t;
		cin >> t;
		cout << dp[t] % (1000000000 + 7) << endl;
	}
}