#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n][3];
    int aim = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        if(a[i][0] + a[i][1] + a[i][2] > 1)
            aim++;
    }

    cout << aim;

    return 0;
}
