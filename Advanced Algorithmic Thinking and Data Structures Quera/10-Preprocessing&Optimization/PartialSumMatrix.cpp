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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<ll>> a;
	vector<vector<ll>> slv;

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++)
	{
		vector<ll> temp;
		for (int j = 0; j < n; j++)
		{
			temp.push_back(0);
		}
		slv.push_back(temp);
	}


	for (int i = 0; i < n; i++)
	{
		vector<ll> temp;
		for (int j = 0; j < n; j++)
		{
			ll t;
			cin >> t;
			temp.push_back(t);

			if (j == 0) slv[i][j] = temp[j];
			else slv[i][j] = slv[i][j - 1] + temp[j];
		}
		a.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			slv[j][i] += slv[j - 1][i];
		}
	}


	while (q--)
	{
		ll x, X, y, Y;
		cin >> x >> y >> X >> Y;
		
		ll sum = slv[X][Y];
		if (x != 0)
		{
			sum -= slv[x - 1][Y];
		}
		if (y != 0)
		{
			sum -= slv[X][y - 1];
		}
		if (x != 0 && y != 0)
		{
			sum += slv[x - 1][y - 1];
		}

		cout << sum << "\n";
	}
}