#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    int sumA = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sumA += a[i];
        sum -= a[i];
        ans++;

        if(sumA > sum) 
        {
            cout << ans;
            break;
        }
    }
    return 0;
}
