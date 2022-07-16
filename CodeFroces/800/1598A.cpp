#include <iostream>

using namespace std;

//A. Computer Game

#define ll long long int

int main()
{
    ll nTest;
    cin >> nTest;

    for (ll t = 1; t <= nTest; t++)
    {
        int n;
        cin >> n;
        
        string a, b;
        cin >> a >> b;

        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1' && b[i] == '1')
            {
                flag = false;
                break;
            }
        }

        if (flag) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

}
