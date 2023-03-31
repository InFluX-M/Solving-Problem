#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int c = 0;
    string aim = "";
    aim.push_back(s[0]);

    for(int i=1; i<n; i++)
    {
        if(s[i] != aim.back())
        {
            aim.push_back(s[i]);
        }
        else
        {
            c++;
        }
    }

    cout << c << endl;
    return 0;
}
