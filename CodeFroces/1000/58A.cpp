#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'h' && j == 0)
            j++;
        if (s[i] == 'e' && j == 1)
            j++;
        if (s[i] == 'l' && j == 2)
            j++;
        else if (s[i] == 'l' && j == 3)
            j++;
        if (s[i] == 'o' && j == 4)
            j++;
    }

    if (j == 5)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
