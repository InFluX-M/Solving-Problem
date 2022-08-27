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

int n, k;
int xf, yf;
int res;

void registQueen(int x, int y, vector<vector<bool>> &slv)
{
	for (int j = 0; j < n; j++)
	{
		slv[x][j] = true;
	}

	for (int i = 0; i < n; i++)
	{
		slv[i][y] = true;
	}

	int i = x, j = y;
	while (i != n && j != n)
	{
		slv[i][j] = true;
		j++;
		i++;
	}

	i = x, j = y;
	while (i != -1 && j != -1)
	{
		slv[i][j] = true;
		j--;
		i--;
	}

	i = x, j = y;
	while (i != n && j != -1)
	{
		slv[i][j] = true;
		j--;
		i++;
	}

	i = x, j = y;
	while (i != -1 && j != n)
	{
		slv[i][j] = true;
		j++;
		i--;
	}
}

bool find(int x, int y, vector<vector<bool>> slv)
{
	for (int i = x; i < n; i++)
	{
		if (i == x)
		{
			for (int j = y; j < n; j++)
			{
				if (!slv[i][j])
				{
					xf = i;
					yf = j;
					return true;
				}
			}
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (!slv[i][j])
				{
					xf = i;
					yf = j;
					return true;
				}
			}
		}

	
	}

	return false;
	
}

void solve(int x, int y, int kn, vector<vector<bool>> slv)
{
	slv[x][y] = true;
	registQueen(x, y, slv);
	kn++;

	if (kn == k)
	{
		res++;
		return;
	}
	
	while (find(x, y, slv))
	{
		slv[xf][yf] = true;
		solve(xf, yf, kn, slv);
	}

}

int main()
{
	set_cout;
	set_cin;

	cin >> n >> k;

	vector<vector<bool>> slv(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			solve(i, j, 0, slv);
		}
	}

	cout << res;
}