#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        ll x1, x2, x3, y1, y2, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (x1 < max(x2, x3) && x1 > min(x2, x3))
        {
            cout << "YES" << endl;
            continue;
        }
        if (y1 < max(y2, y3) && y1 > min(y2, y3))
        {
            cout << "YES" << endl;
            continue;
        }
        if (x2 < max(x1, x3) && x2 > min(x1, x3))
        {
            cout << "YES" << endl;
            continue;
        }
        if (y2 < max(y1, y3) && y2 > min(y1, y3))
        {
            cout << "YES" << endl;
            continue;
        }
        if (x3 < max(x2, x1) && x3 > min(x2, x1))
        {
            cout << "YES" << endl;
            continue;
        }
        if (y3 < max(y2, y1) && y3 > min(y2, y1))
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
