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

vector<vector<int>> adj;
vector<bool> mark;

void DFS(int v) {
	mark[v] = true;
	for (auto u : adj[v])
		if (!mark[u]) DFS(u);

}

int main()
{
	set_cout;
	set_cin;

	int q;
	cin >> q;

	fill_n(back_inserter(adj), q, vector<int>());
	fill_n(back_inserter(mark), q, false);

	vector<pair<int, int>> points;
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	int s = 0;
	for (int i = 0; i < q; i++)
	{
		for (int j = i + 1; j < q; j++)
		{
			if (points[i].first == points[j].first || points[i].second == points[j].second)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
				s++;
			}
		}
	}

	int c = 0;
	for (int i = 0; i < q; i++) {
		if (mark[i]) continue;

		DFS(i);
		c++;
	}

	cout << c - 1;

}
