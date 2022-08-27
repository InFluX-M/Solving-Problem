#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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



void DFS(int v, vector<bool>& mark, vector<set<int>>& ADJ)
{
	mark[v] = true;
	for (int t : ADJ[v])
	{
		if (!mark[t])
		{
			DFS(t, mark, ADJ);
		}
	}
}

int main()
{
	set_cout;
	set_cin;

	int n, m;
	int t, s;

	cin >> n >> m;
	cin >> t >> s;

	vector<bool> mark(n, false);
	vector<set<int>> ADJ(n, set<int>());

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		ADJ[x-1].insert(y-1);
		ADJ[y-1].insert(x-1);
	}

	DFS(t - 1, mark, ADJ);

	if (mark[t-1] && mark[s-1]) cout << "YES";
	else cout << "NO";
}

