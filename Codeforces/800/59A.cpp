#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int c = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] <= 'Z') c++;
    }

    if(c > s.length()/2)
    {
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] > 'Z') s[i] = s[i] - 32;
        }
    }
    else
    {
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] <= 'Z') s[i] = s[i] + 32;
        }
    }

    cout << s << endl;
    return 0;
}
