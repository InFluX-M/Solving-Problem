#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <math.h>
#include <cmath>


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

int main()
{
	vector<ll> dp;
	dp.push_back(1);
	dp.push_back(3);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		dp.push_back(4 * dp[i - 1] - dp[i - 2]);
	}

	if (n % 2 == 1) cout << 0;
	else cout << 2*dp[n/2];
}
