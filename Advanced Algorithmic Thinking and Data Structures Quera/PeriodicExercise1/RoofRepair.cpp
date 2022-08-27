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
	vector<ll> a;
	vector<ll> b;

	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		ll t;
		cin >> t;
		a.push_back(t);
		b.push_back(0);
	}

	ll j = n - 1;
	ll min = a[j];
	b[j] = min;

	while (j > 0)
	{
		if (min <= a[j - 1])
		{
			b[j-1] = min;
		}
		else
		{
			min = a[j - 1];
			b[j-1] = min;
		}

		j--;
	}

	ll i = -1;
	j = 0;
	min = b[j];
	ll s = 0;
	while (j < n - 1)
	{
		if (min < b[j + 1])
		{
			s += (j - i) * min;
			i = j;
			min = b[j + 1];
		}
		if (j == n - 2)
		{
			s += (j + 1 - i) * min;
		}
		j++;
	}

	if (n == 1) cout << a[0];
	else cout << s;

}