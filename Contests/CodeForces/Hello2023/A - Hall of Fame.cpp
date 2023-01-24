#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
 
        bool state1 = false;
        bool state2 = false;
        int iState2 = -1;
 
        for(int i=0; i<n-1; i++)
        {
            if(s[i]=='R' && s[i+1]=='L') state1 = true;
            if(s[i]=='L' && s[i+1]=='R')
            {
                state2 = true;
                iState2 = i;
            }
        }
 
        if(state1) cout << 0;
        else if(state2) cout << (iState2+1);
        else cout << -1;
 
        cout << "\n";
    }
    return 0;
}