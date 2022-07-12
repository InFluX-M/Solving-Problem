#include <iostream>
#include <cmath>

using namespace std;

//B. Make It Increasing
#define ll long long int

int main()
{
    ll nTest;
    cin >> nTest;

    for (ll t = 1; t <= nTest; t++)
    {
        ll n;
        cin >> n;
  
        ll* a = new ll[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        bool flag = false;
        int oP = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i - 1] == 0 && a[i] == 0)
            {
                flag = true;
                break;
            }
            else if (a[i] == 0 && a[i - 1] > a[i])
            {
                flag = true;
                break;
            }
            else
            {
                while (a[i - 1] >= a[i])
                {
                    a[i - 1] = a[i - 1] / 2.0;
                    oP++;
                }
            }
        }

        if (flag) cout << -1;
        else cout << oP;

        cout << "\n";

    }

}
