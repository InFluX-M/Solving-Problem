#include <iostream>

using namespace std;

int main()
{
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; i++)
    {
        int first, last, nOperation;
        cin >> first >> last >> nOperation;

        int nOdd = 0;
 
        if ((last - first) % 2 == 0)
        {
            if (first % 2 == 0) nOdd += (last - first + 1) / 2;
            else nOdd += (last - first + 1) / 2 + 1;
        }
        else if ((last - first) % 2 == 1)
        {
            nOdd += (last - first + 1) / 2;
        }

        if (last - first == 0 && last != 1) cout << "YES";
        else if (nOdd > nOperation) cout << "NO";
        else cout << "YES";

        cout << "\n";

    }
}
