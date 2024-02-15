#include <iostream>
#include <algorithm>
using namespace std;

//B. Shoe Shuffling

int main()
{
    int nTest;
    cin >> nTest;

    for (int t = 1; t <= nTest; t++)
    {
        int n;
        cin >> n;

        int* a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool flag = false;
        int r = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
            {
                r++;
            }
            else
            {
                if (r == 0) flag = true;
                else r = 0;
            }  
        }
        if (a[n - 2] != a[n - 1]) flag = true;

        int* j = new int[n];
        for (int i = 0; i < n; i++)
        {
            j[i] = i + 1;
        }

        if (n == 1) cout << -1;
        else if (flag) cout << -1;
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (a[i] == a[i + 1])
                {
                    int k = j[i];
                    j[i] = j[i + 1];
                    j[i + 1] = k;
                }
            }

            for (int i = 0; i < n; i++)
            {
                cout << j[i] << " ";
            }
        }
        
        cout << endl;
    }

}
