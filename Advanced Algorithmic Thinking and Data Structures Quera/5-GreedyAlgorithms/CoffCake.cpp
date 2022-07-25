#include <iostream>
#include <algorithm>
#include <vector>

#define max_vec(vec) *max_element(vec.begin(), vec.end())
#define min_vec(vec) *min_element(vec.begin(), vec.end())

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> vc;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		vc.push_back(t);
	}

	if (k == 1) cout << max_vec(vc);
	else if (k > 2) cout << min_vec(vc);
	else cout << min(vc[0], vc[n - 1]);

	cout << "\n";
}