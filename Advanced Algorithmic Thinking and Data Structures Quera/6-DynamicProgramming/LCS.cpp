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
typedef vector<int> vector_int;

#define find_vec(vec, item, first_index, last_index) find(vec.begin()+first_index, vec.begin()+last_index+1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin()+first_index, vec.begin()+last_index+1, 0)

void reverseStr(string& str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}
string pathDP(string aimPath, int i, int j);

vector<vector_ll> dp;
vector<vector<int>> path;
string s1, s2;

int main()
{
	cin >> s1 >> s2;

	ll lenS1 = s1.length();
	ll lenS2 = s2.length();

	for (int i = 0; i <= lenS1; i++)
	{
		vector_ll t;
		vector_int t1;
		for (int j = 0; j <= lenS2; j++)
		{
			t.push_back(-1);
			t1.push_back(-1);
		}
		dp.push_back(t);
		path.push_back(t1);
	}

	for (int i = 0; i <= lenS1; i++)
	{
		for (int j = 0; j <= lenS2; j++)
		{
			if (i == 0)
			{
				path[i][j] = 2;
				dp[i][j] = 0;
				continue;
			}
			if (j == 0)
			{
				path[i][j] = 1;
				dp[i][j] = 0;
				continue;
			}

			if (s1[i-1] == s2[j-1])
			{
				path[i][j] = 0;
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
					path[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
					path[i][j] = 2;
				}
			}
		}
	}

	string aimPath = "";
	aimPath = pathDP(aimPath, lenS1, lenS2);
	reverseStr(aimPath);
	cout << dp[lenS1][lenS2] << endl << aimPath;

}

string pathDP(string aimPath, int i, int j)
{
	if (i == 0 || j == 0) return aimPath;

	if (path[i][j] == 0)
	{
		aimPath += s1[i-1];
		return pathDP(aimPath, i - 1, j - 1);
	}
	else if (path[i][j] == 1)
	{
		return pathDP(aimPath, i - 1, j);
	}
	else if (path[i][j] == 2)
	{
		return pathDP(aimPath, i, j - 1);
	}
}