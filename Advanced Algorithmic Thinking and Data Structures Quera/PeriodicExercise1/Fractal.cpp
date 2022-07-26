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

#define find_vec(vec, item, first_index, last_index) find(vec.begin()+first_index, vec.begin()+last_index+1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin()+first_index, vec.begin()+last_index+1, 0)

vector<vector<char>> base;
vector<vector<char>> finalAim;

int n;
int kAim;
void fractal(int k, vector<vector<char>> aim);

int main()
{
	cin >> n >> kAim;

	for (int i = 0; i < n; i++)
	{
		vector<char> t;
		for (int j = 0; j < n; j++)
		{
			char k;
			cin >> k;
			t.push_back(k);
		}

		base.push_back(t);
		
	}
	vector<vector<char>> aim;


	for (int i = 0; i < n; i++)
	{
		vector<char> t;
		for (int j = 0; j < n; j++)
		{
			t.push_back(base[i][j]);
		}
		aim.push_back(t);
	}


	fractal(1, aim);


	for (int i = 0; i < pow(n, kAim); i++)
	{
		for (int j = 0; j < pow(n, kAim); j++) cout << finalAim[i][j];
		
		cout << endl;
	}
}

void fractal(int k, vector<vector<char>> aim)
{
	if (k == kAim)
	{
		finalAim = aim;
		return;
	}
	k++;

	vector<vector<char>> aimF;
	for (int i = 0; i < pow(n, k); i++)
	{
		vector<char> t;
		aimF.push_back(t);
	}

	for (int i = 0; i < pow(n,k-1); i++)
	{
		for (int j = 0; j < pow(n, k-1); j++)
		{
			char u = aim[i][j];
			if (u == '.')
		        for (int k = 0; k < n; k++) for (int l = 0; l < n; l++) aimF[k + i*n].push_back(base[k][l]);
			
			else if (u == '*')
			    for (int k = 0; k < n; k++) for (int l = 0; l < n; l++) aimF[k + i*n].push_back('*');
			
		}
	}

	fractal(k, aimF);
}
