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

#define find_vec(vec, item, first_index, last_index) find(vec.begin()+first_index, vec.begin()+last_index+1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin()+first_index, vec.begin()+last_index+1, 0)

ll k = 0;
vector_ll solve(vector_ll a);

int main()
{
	ll n;
	cin >> n;

	vector_ll a;

	for (int i = 0; i < n; i++)
	{
		ll t;
		cin >> t;
		a.push_back(t);
	}

	solve(a);
	cout << k;
}

vector_ll solve(vector_ll a)
{
	if (a.size() == 1 || a.size() == 0) return a;
	if (a.size() == 2)
	{
		if (a[1] < a[0])
		{
			ll t = a[0];
			a[0] = a[1];
			a[1] = t;

			k++;
		}
		return a;
	}

	vector_ll a1, a2;

	for (int i = 0; i < a.size() / 2; i++)
	{
		a1.push_back(a[i]);
	}
	for (int i = a.size() / 2; i < a.size(); i++)
	{
		a2.push_back(a[i]);
	}

	a1 = solve(a1);
	a2 = solve(a2);

	vector<ll> finalAim;

    int i = 0;
    int j = 0;

    while (i <= a1.size() - 1 && j <= a2.size() - 1)
    {

        if (a1[i] > a2[j])
        {
            finalAim.push_back(a2[j]);
            j++;
			k+=a1.size()-i;
        }
        else
        {
            finalAim.push_back(a1[i]);
            i++;
        }
    }

    while (i <= a1.size() - 1)
    {
        finalAim.push_back(a1[i]);
        i++;
    }
    while (j <= a2.size() - 1)
    {
        finalAim.push_back(a2[j]);
        j++;
    }

	return finalAim;
}
