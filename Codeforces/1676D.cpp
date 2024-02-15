#include <iostream>
using namespace std;

//D. X-Sum
#define ll long long int

int main()
{
    ll nTest;
    cin >> nTest;

    for (ll t = 1; t <= nTest; t++)
    {
        ll n, m;
        cin >> n >> m;
  
        ll** a = new ll* [n];
        for (int i = 0; i < n; i++)
        {
            a[i] = new ll[m];
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                a[i][j] = 0;
            }
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        ll maxValue = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                ll r = i + 1, c = j + 1;
                ll value = a[i][j];
                while (r < n && c < m)
                {
                    value += a[r][c];
                    r++;
                    c++;
                }

                r = i - 1, c = j - 1;
                while (r >= 0 && c >= 0)
                {
                    value += a[r][c];
                    r--;
                    c--;
                }

                r = i - 1, c = j + 1;
                while (r >= 0 && c < m)
                {
                    value += a[r][c];
                    r--;
                    c++;
                }

                r = i + 1, c = j - 1;
                while (r < n && c >= 0)
                {
                    value += a[r][c];
                    r++;
                    c--;
                }

                if (value > maxValue) maxValue = value;

            }
        }

        cout << maxValue;
        cout << "\n";
    }

}
