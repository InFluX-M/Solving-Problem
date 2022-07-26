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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int j=0, k=0, l=0, m=0;
	if (a < c)
	{
		if (a % 2 == 1)
		{
			j += a / 2 + 1;
			k += a / 2;
			l += a / 2;
			m += a / 2;
		}
		else
		{
			j += a / 2;
			k += a / 2;
			l += a / 2;
			m += a / 2 - 1;
		}
	}
	else if (a > c)
	{
		if (c % 2 == 1)
		{
			j += c / 2 + 1;
			k += c / 2+1;
			l += c / 2;
			m += c / 2;
		}
		else
		{
			j += c / 2;
			k += c / 2;
			l += c / 2;
			m += c / 2;
		}
	}
	else
	{
		if (c % 2 == 1)
		{
			j += c / 2 + 1;
			k += c / 2 + 1;
			l += c / 2;
			m += c / 2;
		}
		else
		{
			j += c / 2;
			k += c / 2;
			l += c / 2;
			m += c / 2;
		}
	}

	cout << j << " " << k << " " << l << " " << m;
}