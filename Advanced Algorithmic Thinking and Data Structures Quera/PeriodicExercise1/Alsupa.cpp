#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

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
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

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

ll solve(vector<ll> a, ll u, ll sum);
void s();

vector<ll> sqaure;
ll k = 0;
ll n;
ll x;
ll up;

int main()
{
	cin >> x >> n;
	s();
	vector<ll> a;
	solve(a, 0, 0);

	cout << k;
}

ll solve(vector<ll> a, ll u, ll sum)
{
	if (sum == x)
	{
		k++;
		return 1;
	}
	else if (sum > x) return 2;

	for (int i = u; i < up; i++)
	{
		sum += sqaure[i];
		ll j = solve(a, i + 1, sum);

		if (j == 2 || j == 1);
		{
			sum -= sqaure[i];
			continue;
		}
	}

}

void s()
{
	ll i = 1;
	while (pow(i, n) <= x)
	{
		ll t = pow(i, n);
		sqaure.push_back(t);
		if (t > x) return;
		i++;
	}
	up = i;
}
