#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    long long int a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    long long int ans = 0;
    long long int pos = 1;
    for (int i = 0; i < m; i++)
    {
        if(pos < a[i])
        {
            ans += a[i] - pos;
            pos = a[i];
        }
        else if(pos > a[i])
        {
            ans += (n-pos+1);
            pos = 1;
            ans += (a[i] - pos);
            pos = a[i];
        }
    }

    cout << ans;
    
    return 0;
}
