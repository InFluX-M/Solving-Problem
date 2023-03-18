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

void solve(int n);

int k = 0;
int main()
{
	int n;
	cin >> n;
	// solve(n);

	int a[n];
	fill_n(a, n, 0);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 5;
	a[4] = 9;

	for (int i = 5; i < n; i++)
	{
		a[i] = a[i-5] + a[i-2] + a[i-1];
	}
	
	// cout << k;
	cout << a[n-1];
}

void solve(int n)
{
	if (n < 0) return;
	if (n == 0)
	{
		k++;
		return;
	}

	solve(n - 1);
	solve(n - 2);
	solve(n - 5);

}

// 1 1 1 1 1
// 1 1 1 2
// 1 2 2 
// 1 2 1 1
// 1 1 2 1
// 2 2 1
// 2 1 1 1
