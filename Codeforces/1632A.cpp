#include <iostream>

using namespace std;

int main()
{
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; i++)
    {
        int lenStr;
        cin >> lenStr;

        string aim;
        cin >> aim;

        if (aim.length() == 1) cout << "YES";
        else if (aim.length() == 2)
        {
            if (aim[0] == aim[1]) cout << "NO";
            else cout << "YES";
        }
        else cout << "NO";

        cout << "\n";
    }
}