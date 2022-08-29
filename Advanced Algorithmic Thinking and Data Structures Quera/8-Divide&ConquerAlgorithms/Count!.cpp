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

ll res;
ll k;

void solve(vector<ll> a)
{
	vector<ll> slv;
	slv.push_back(a[0]);
	for (int i = 1; i < a.size(); i++)
	{
		slv.push_back(slv[i - 1] + a[i]);
	}

	sort(slv.begin(), slv.end());

	for (vector<ll>::iterator i = slv.begin(); i != slv.end(); i++)
	{
		if (*i > k || *i < -1 * k) res++;
		//if (i != slv.end())
		//{
		//	res += (slv.end() - upper_bound(i + 1, slv.end(), k + *i));
		//}
		if (i != slv.begin())
		{
			res += (lower_bound(slv.begin(), i, *i - k) - slv.begin());
		}
	}

}

int main()
{
	set_cout;
	set_cin;

	ll t;
	cin >> t;

	while (t--)
	{
		res = 0;

		ll n;
		cin >> n >> k;

		vector<ll> a;
		for (int i = 0; i < n; i++)
		{
			ll t;
			cin >> t;
			a.push_back(t);
		}

		solve(a);

		cout << res << "\n";
	}


}