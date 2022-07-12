#include <iostream>
#include <algorithm>
using namespace std;

//A. Creep

int main()
{
    int nTest;
    cin >> nTest;

    for (int t = 1; t <= nTest; t++)
    {
        int n0, n1;
        cin >> n0 >> n1;

        string aim = "";

        for (int i = 0; i < min(n0, n1); i++) aim += "01";

        for (int i = 0; i < max(n0, n1) - min(n0, n1); i++)
        {
            if (n0 > n1) aim += "0";
            else aim += "1";
        }

        cout << aim << "\n";
    }

}
