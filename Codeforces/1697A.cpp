#include <iostream>
using namespace std;

//A. Parkway Walk

int main()
{
    int nTest;
    cin >> nTest;

    for (int t = 1; t <= nTest; t++)
    {
        int n, m;
        cin >> n >> m;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            sum += a;
        }

        if (m - sum < 0) cout << sum - m;
        else cout << 0;

        cout << "\n";
    }

}
