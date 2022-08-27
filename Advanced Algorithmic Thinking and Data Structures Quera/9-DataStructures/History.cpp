#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stack>
#include <string>

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
	
	vector_char aim;
	stack<vector_char> solve;

	for (int i = 0; i < 1000; i++) aim.push_back(' ');
	solve.push(aim);

	int q;
	cin >> q;

	while (q--)
	{
		string s;
		cin >> s;

		if (s == "insert")
		{
			int index;
			cin >> index;

			char c;
			cin >> c;

			if (aim[index - 1] == ' ') erace_item_vec(aim, index - 1);
			aim.insert(aim.begin() + index - 1, c);
			
			solve.push(aim);
		}
		else if (s == "delete")
		{
			int index;
			cin >> index;

			erace_item_vec(aim, index - 1);
			solve.push(aim);
		}
		else if (s == "undo")
		{
			solve.pop();
			aim = solve.top();
		}
	}

	for (char t : aim) cout << t;
}
