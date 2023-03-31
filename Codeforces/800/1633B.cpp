#include <iostream>

using namespace std;

int main()
{
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; i++)
    {
        string minority;
        cin >> minority;

        int n0 = 0;
        int n1 = 0;

        for (int k = 0; k < minority.length(); k++)
        {
            n0 = 0;
            n1 = 0;

            for (int j = k; j < minority.length(); j++)
            {
                if (minority[j] == '0') n0++;
                else n1++;

            }

            if (n0 > n1)
            {
                cout << n1;
                break;
            }
            else if (n0 < n1)
            {
                cout << n0;
                break;
            }
        }

        if (n0 == n1) cout << 0;
        cout << "\n";
    }
}
