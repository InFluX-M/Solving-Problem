#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <math.h>
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
#define set_cout ios_base::sync_with_stdio(false)
#define set_cin cin.tie(NULL)

int main()
{
	set_cout;
	set_cin;

	int q;
	cin >> q;

	while (q--)
	{
		int n;
		cin >> n;
		vector<vector<int>> a;
		for (int i = 0; i < n; i++)
		{
			vector<int> temp;
			for (int j = 0; j < i + 1; j++)
			{
				int t;
				cin >> t;
				temp.push_back(t);
			}
			a.push_back(temp);
		}

		vector<vector<int>> dp(n, vector<int>(n, 0));
		vector<int> temp;
		temp.push_back(a[0][0]);
		dp[0] = temp;

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				if (j == 0) dp[i][j] = dp[i - 1][j] + a[i][j];
				else if (j == i) dp[i][j] = dp[i - 1][j - 1] + a[i][j];
				else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
			}
		}

		int res = 0;
		for (int j = 0; j < n; j++)
		{
			res = max(res, dp[n - 1][j]);
		}

		cout << res << "\n";
	}

}