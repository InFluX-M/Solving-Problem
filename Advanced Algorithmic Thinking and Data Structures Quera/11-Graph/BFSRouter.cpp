#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

int main()
{
	set_cout;
	set_cin;

	int n, m;
	int s, t;

	cin >> n >> m;
	cin >> s >> t;

	vector<set<int>> ADJ(n, set<int>());
	vector<pair<int, vector<int>>> DISTANCE(n, make_pair(100001, vector<int>()));

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		ADJ[x - 1].insert(y - 1);
		ADJ[y - 1].insert(x - 1);
	}

	queue<int> q;
	q.push(s-1);
	DISTANCE[s-1].first = 0;
	DISTANCE[s-1].second.push_back(s-1);

	while (q.size() > 0)
	{
		int v = q.front();
		q.pop();

		for (int u : ADJ[v])
		{
			if (DISTANCE[u].first > DISTANCE[v].first + 1)
			{
				DISTANCE[u].first = DISTANCE[v].first + 1;
				DISTANCE[u].second = DISTANCE[v].second;
				DISTANCE[u].second.push_back(u);
				q.push(u);
			}
		}
	}

	if (DISTANCE[t - 1].first >= 100001) cout << -1;
	else
	{
		cout << DISTANCE[t - 1].first << "\n";
		for (int v : DISTANCE[t - 1].second) cout << v + 1 << " ";
	}
}