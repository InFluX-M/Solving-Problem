#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int

using namespace std;

int main()
{
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> vec;

	for (ll i = 0; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}

	sort(vec.begin(), vec.end());
	

	for (ll i = 0; i < n; i++)
	{
		if (vec[i].second - vec[i].first >= 0 && k >= vec[i].first)
		{
			k += vec[i].second - vec[i].first;
		}
	}

	cout << k;
}