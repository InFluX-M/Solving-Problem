#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef vector<ll> vector_ll;
typedef vector<string> vector_string;
typedef vector<char> vector_char;
typedef vector<bool> vector_bool;

#define find_vec(vec, item, first_index, last_index) find(vec.begin() + first_index, vec.begin() + last_index + 1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin() + first_index, vec.begin() + last_index + 1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin() + first_index, vec.begin() + last_index + 1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin() + first_index, vec.begin() + last_index + 1, 0)

char **base;
char **finalAim;
char aim[343][343];

int n;
int kAim;
void fractal(int k, char **aim)
{
	if (k == kAim)
	{
		finalAim = aim;
		return;
	}

	k++;

	char **temp = new char *[int(pow(n, k))];
	for (int i = 0; i < pow(n, k); i++)
		temp[i] = new char[int(pow(n, k))];

	for (int i = 0; i < pow(n, k - 1); i++)
	{
		for (int j = 0; j < pow(n, k - 1); j++)
		{
			for (int k = i * n; k < i * n + n; k++)
			{
				for (int l = j * n; l < j * n + n; l++)
				{
					temp[k][l] = (aim[i][j] == '*') ? '*' : base[k - i * n][l - j * n];
				}
			}
		}
	}

	fractal(k, temp);
}

int main()
{
	cin >> n >> kAim;

	base = new char *[n];
	for (int j = 0; j < n; j++)
	{
		base[j] = new char[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> base[i][j];
		}
	}

	char **aim = new char *[n];
	for (int j = 0; j < n; j++)
	{
		aim[j] = new char[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			aim[i][j] = base[i][j];
		}
	}

	fractal(1, aim);

	for (int i = 0; i < pow(n, kAim); i++)
	{
		for (int j = 0; j < pow(n, kAim); j++)
			cout << finalAim[i][j];

		cout << "\n";
	}
}