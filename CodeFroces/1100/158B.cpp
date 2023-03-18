#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);

    int sum = 0;
    int ans = 0;

    for (int i = 0; i < n-1; i++)
    {
        sum += a[i];

        if(sum+a[i+1] > 4)
        {
            ans++;
            sum = 0;
        }
    }

    if(sum+a[n-1] > 4)
        ans+=2;
    else
        ans++;
        
    cout << ans << endl;
    return 0;
}
