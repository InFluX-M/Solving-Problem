#include <iostream>
#include <algorithm>

using namespace std;

//C. Restoring the Duration of Tasks

int main()
{
    int nTest;
    cin >> nTest;

    for (int t = 1; t <= nTest; t++)
    {
        int n;
        cin >> n;


        int* s = new int[n];
        int* f = new int[n];
        int* d = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            d[i] = 0;
        }
        for (int i = 0; i < n; i++) cin >> f[i];


        d[0] = f[0] - s[0];
        for (int i = 1; i < n; i++)
        {
            if (f[i - 1] > s[i]) s[i] = f[i - 1];
            d[i] = f[i] - s[i];
        }

        for (int i = 0; i < n; i++) cout << d[i] << " ";
  
        cout << endl;
    }

}
