#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <list>

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
	list<char> solve;

	int q;
	cin >> q;

	list<char> ::iterator aim = solve.begin();

	while (q--)
	{
		string s;
		cin >> s;

		if (s == "insert")
		{
			char c;
			cin >> c;

			solve.insert(aim, c);
		}
		else if (s == "+")
		{
			if (aim != solve.end()) aim++;
		}
		else
		{
			if (aim != solve.begin()) aim--;
		}
	}

	for (auto t : solve) cout << t;
}
