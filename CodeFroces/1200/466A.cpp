#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = 0;

    if (1.0 * b / m < a)
    {
        ans += (n / m) * b;

        if (n % m != 0)
        {
            if ((n % m) * a > b)
                ans += b;
            else
                ans += (n % m) * a;
        }
    }
    else 
    {
        ans = n*a;
    }

    cout << ans;

    return 0;
}
