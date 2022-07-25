#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

#define ll long long int

#define find_vec(vec, item, first_index, last_index) find(vec.begin()+first_index, vec.begin()+last_index+1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin()+first_index, vec.begin()+last_index+1, 0)

vector<pair<string, bool>> statue;
int n;
string m;

void reset();
bool pr();
void re();

int main()
{
	cin >> n;
	getchar();

	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		statue.push_back(make_pair(s, false));
	}

	int q;
	cin >> q;
	getchar();

	int l = 0;
	for (int k = 0; k < q; k++)
	{
		getline(cin, m);
		re();
		if (pr())
		{
			l++;
			reset();
		}
	}

	cout << l;
}

void reset()
{
	for (int i = 0; i < n; i++)
	{
		if (statue[i].first == m) continue;
		statue[i].second = false;
	}
}

bool pr()
{
	for (int i = 0; i < n; i++) if (statue[i].second == false) return false;
	return true;
}

void re()
{
	for (int i = 0; i < n; i++)
	{
		if (statue[i].first == m)
		{
			statue[i].second = true;
			return;
		}
	}
}