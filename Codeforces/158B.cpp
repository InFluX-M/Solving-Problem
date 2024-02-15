#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int c[4];
    fill_n(c, 4, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i] - 1]++;
    }

    int ans = 0;

    ans += c[3];
    c[3] = 0;

    c[0] -= c[2];
    ans += c[2];

    ans += c[1] / 2;
    c[1] %= 2;

    if (c[1])
    {
        c[0] -= 2;
        ans++;
    }

    if (c[0] > 0)
        ans += c[0] / 4 + (c[0] % 4 != 0);

    cout << ans << endl;
    return 0;
}
