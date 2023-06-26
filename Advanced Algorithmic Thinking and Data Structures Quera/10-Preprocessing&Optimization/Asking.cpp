#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

typedef long long int ll;
typedef vector<ll> vector_ll;
typedef vector<string> vector_string;
typedef vector<char> vector_char;
typedef vector<bool> vector_bool;

int main()
{
	vector<set<ll>> slv;

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++)
	{
		set<ll> t;
		t.insert(i + 1);
		slv.push_back(t);
	}

	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int i, j;
			cin >> i >> j;
			slv[j - 1].insert(slv[i - 1].begin(), slv[i - 1].end());
			slv[i - 1].clear();
		}
		else if (t == 2)
		{
			int i;
			cin >> i;
			cout << slv[i - 1].size() << "\n";
		}
		else if (t == 3)
		{
			int i;
			cin >> i;
			if (slv[i - 1].size())
			{
				for (ll temp : slv[i - 1])
					cout << temp << " ";
				cout << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
	}
	
}