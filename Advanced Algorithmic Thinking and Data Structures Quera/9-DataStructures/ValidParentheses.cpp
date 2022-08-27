#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>

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

int main()
{
	stack<int> a;
	vector<pair<int, int>> solve;

	string s;
	cin >> s;
	

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			a.push(i);
		}
		else if (s[i] == ')')
		{
			if (a.empty())
			{
				cout << -1;
				return 0;
			}
			else
			{
				solve.push_back(make_pair(a.top() + 1, i + 1));
				a.pop();
			}
		}


	}

	if (!a.empty()) cout << -1;
	else for (pair<int, int> t : solve) cout << t.first << " " << t.second << "\n";
}
