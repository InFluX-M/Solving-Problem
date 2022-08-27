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

int main()
{
	set_cout;
	set_cin;

	int n;
	cin >> n;

	vector<vector<int>> ADJ(n, vector<int>());
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		ADJ[x - 1].push_back(y - 1);
		ADJ[y - 1].push_back(x - 1);
	}


	vector<int> DIST(n, 1000000);
	DIST[0] = 0;
	queue<int> q;
	q.push(0);
	while (q.size() > 0)
	{
		int v = q.front();
		q.pop();

		for (int u : ADJ[v])
		{
			if (DIST[u] > DIST[v] + 1)
			{
				DIST[u] = DIST[v] + 1;
				q.push(u);
			}
		}
	}
	int maxD = -1;
	int ImaxD = -1;
	for (int i = 0; i < n; i++)
	{
		if (DIST[i] > maxD)
		{
			maxD = DIST[i];
			ImaxD = i;
		}
	}

	vector<int> DIST2(n, 1000000);
	DIST2[ImaxD] = 0;
	queue<int> q1;
	q1.push(ImaxD);
	while (q1.size() > 0)
	{
		int v = q1.front();
		q1.pop();

		for (int u : ADJ[v])
		{
			if (DIST2[u] > DIST2[v] + 1)
			{
				DIST2[u] = DIST2[v] + 1;
				q1.push(u);
			}
		}
	}
	int maxS = -1;
	for (int i = 0; i < n; i++)
	{
		if (DIST2[i] > maxS)
		{
			maxS = DIST2[i];
		}
	}

	cout << maxS;
}

