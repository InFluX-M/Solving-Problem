#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
 
        if(n == 3)
        {
            cout << "NO\n";
        }
        else if (n % 2 == 0)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                cout << pow(-1, i+1) * (1) << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "YES\n";
            int p = n / 2;
            int s = -1*(n/2-1);
            for (int i = 0; i < n; i++)
            {
                cout << (i%2==0 ? s : p) << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}