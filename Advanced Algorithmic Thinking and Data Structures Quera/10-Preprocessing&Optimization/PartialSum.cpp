#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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
	int n;
	int q;

	cin >> n >> q;

	vector_ll a;
	for (int i = 0; i < n; i++)
	{
		ll t;
		cin >> t;
		a.push_back(t);
	}

	vector_ll slv;
	slv.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		slv.push_back(slv[i - 1] + a[i - 1]);
	}

	while (q--)
	{
		ll r, l;
		cin >> r >> l;

		if (r == 0)
		{
			cout << slv[l + 1] << "\n";
		}
		else
		{
			cout << slv[l + 1] - slv[r] << "\n";
		}
	}

}

