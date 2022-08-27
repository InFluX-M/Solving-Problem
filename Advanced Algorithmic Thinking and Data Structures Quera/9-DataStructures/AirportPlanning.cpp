#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
	set<long long int> slv;

	long long int q, k;
	cin >> q >> k;

	vector<string> s;

	while (q--)
	{
		long long int t;
		cin >> t;

		if (slv.find(t) != slv.end())
		{
			s.push_back("Permission Denied!");
		}
		else
		{
			slv.insert(t);

			set<long long int>::iterator lb = --slv.lower_bound(t);
			set<long long int>::iterator ub = slv.upper_bound(t);

			if (lb == slv.end() && ub == slv.end())
			{
				s.push_back("Permission Granted!");
			}
			else if (lb == slv.end())
			{
				if (abs(*ub - t) >= k)
				{
					s.push_back("Permission Granted!");
				}
				else
				{
					s.push_back("Permission Denied!");
					slv.erase(t);
				}

			}
			else if (ub == slv.end())
			{
				if (fabs(*lb - t) >= k)
				{
					s.push_back("Permission Granted!");
				}
				else
				{
					s.push_back("Permission Denied!");
					slv.erase(t);
				}
			}
			else
			{
				if (fabs(*ub - t) >= k && fabs(*lb - t) >= k)
				{
					s.push_back("Permission Granted!");
				}
				else
				{
					s.push_back("Permission Denied!");
					slv.erase(t);
				}
			}

		}
	}

	for (string t : s)
	{
		cout << t << endl;
	}

	return 0;
}
