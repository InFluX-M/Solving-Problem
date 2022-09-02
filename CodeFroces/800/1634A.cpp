#include <iostream>
using namespace std;

string reverse(string aim)
{
    string re = "";
    for (int i = aim.length() - 1; i >= 0; i--) re += aim[i];
    return re;

}
int main()
{
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; i++)
    {
        int lenString;
        int nOperation;

        cin >> lenString >> nOperation;

        string myString;
        cin >> myString;

        int n = 1;

        for (int j = 1; j <= nOperation; j++)
        {
            if (myString == reverse(myString)) break;
            else
            {
                n *= 2;

                myString += reverse(myString);
            }
        }

        cout << n << "\n";
            
    }

}
