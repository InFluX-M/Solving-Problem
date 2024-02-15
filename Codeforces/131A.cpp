#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    bool flag = true;
    for(int i=1; i<s.length(); i++)
    {
        if(s[i] > 'Z')
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {
        if(s[0] > 'Z')
            s[0] = s[0] - 32;
        else
            s[0] = s[0] + 32;
        for(int i=1; i<s.length(); i++)
        {
            s[i] = s[i] + 32;
        }
    }

    cout << s << endl;
    
    return 0;
}
