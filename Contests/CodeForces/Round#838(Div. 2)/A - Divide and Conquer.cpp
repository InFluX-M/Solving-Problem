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
 
        vector<int> a;
        int nEven = 0, nOdd = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
 
            if (x % 2 == 0)
                nEven++;
            else
                nOdd++;
            a.push_back(x);
        }
 
        if (nOdd % 2 == 1)
        {
            int minOp = 1000000000;
 
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 1)
                {
                    int op = 0;
                    int temp = a[i];
                    while (temp % 2 != 0)
                    {
                        temp = temp / 2;
                        op++;
                    }
 
                    minOp = min(minOp, op);
                }
                else
                {
                    int op = 0;
                    int temp = a[i];
                    while (temp % 2 != 1)
                    {
                        temp = temp / 2;
                        op++;
                    }
 
                    minOp = min(minOp, op);
                }
            }
 
            cout << minOp << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}