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

set<pair<int, int>> res;
int n, k;

void solve(int x, int y, int kn)
{
	if (k == kn)
	{
		res.insert(make_pair(x, y));
		return;
	}

	if (x + 2 < n && y + 1 < n) solve(x + 2, y + 1, kn + 1);
	if (x + 1 < n && y + 2 < n) solve(x + 1, y + 2, kn + 1);
	if (x + 2 < n && y - 1 > -1) solve(x + 2, y - 1, kn + 1);
	if (x + 1 < n && y - 2 > -1) solve(x + 1, y - 2, kn + 1);
	if (x - 2 > -1 && y + 1 < n) solve(x - 2, y + 1, kn + 1);
	if (x - 1 > -1 && y + 2 < n) solve(x - 1, y + 2, kn + 1);
	if (x - 2 > -1 && y - 1 > -1) solve(x - 2, y - 1, kn + 1);
	if (x - 1 > -1 && y - 2 > -1) solve(x - 1, y - 2, kn + 1);
	
}

int main()
{
	set_cout;
	set_cin;
	cin >> n >> k;
	solve(0, 0, 0);
	cout << res.size();
}