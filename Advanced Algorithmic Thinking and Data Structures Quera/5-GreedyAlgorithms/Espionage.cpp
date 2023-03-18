#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define find_vec(vec, item, first_index, last_index) find(vec.begin() + first_index, vec.begin() + last_index + 1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin() + first_index, vec.begin() + last_index + 1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin() + first_index, vec.begin() + last_index + 1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin() + first_index, vec.begin() + last_index + 1, 0)

set<string> statue;
int n;
string m;

int main()
{
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
	}

	int q;
	cin >> q;
	cin.ignore();

	int l = 0;

	for (int k = 0; k < q; k++)
	{
		getline(cin, m);
		if (statue.find(m) == statue.end() && statue.size() == n - 1 && k != q - 1)
		{
			l++;
			statue.clear();
		}
		statue.insert(m);
	}

	cout << l;
}
