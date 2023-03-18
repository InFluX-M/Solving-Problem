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

	if (k == 1)
		cout << max_vec(vc);
	else if (k > 2)
		cout << min_vec(vc);
	else
	{
		int aim = 5000;
		for (int i = 1; i < n; i++)
		{
			int maxR = vc[n - 1], maxL = vc[0];

			for (int j = 0; j < i; j++)
			{
				maxL = max(maxL, vc[j]);
			}
			for (int j = i; j < n; j++)
			{
				maxR = max(maxR, vc[j]);
			}

			aim = min(aim, min(maxR, maxL));
		}

		cout << aim;
	}

	cout << "\n";
}