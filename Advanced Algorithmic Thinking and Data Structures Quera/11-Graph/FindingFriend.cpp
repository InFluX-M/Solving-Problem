#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
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

int main()
{
	set_cout;
	set_cin;

	int n;
	int m;

	cin >> n;
	vector<int> DIST(n, 10000);
	DIST[0] = 0;
	vector<vector<int>> ADJ(n, vector<int>());

	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;

		ADJ[x - 1].push_back(y - 1);
		ADJ[y - 1].push_back(x - 1);
	}

	int q;
	vector<bool> statue(n, false);
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		statue[x - 1] = true;
	}

	queue<int> qu;
	qu.push(0);

	while (!qu.empty())
	{
		int v = qu.front();
		qu.pop();

		for (auto u : ADJ[v])
		{
			if (DIST[u] > DIST[v] + 1)
			{
				DIST[u] = DIST[v] + 1;
				qu.push(u);
			}
		}
	}

	int minD = 1000000, indexD = -1;
	for (int i = 1; i < n; i++)
	{
		if (DIST[i] < minD && statue[i])
		{
			minD = DIST[i];
			indexD = i;
		}
	}

	cout << indexD + 1;
}

