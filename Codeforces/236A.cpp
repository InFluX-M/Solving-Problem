#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> m;

    for(int i=0; i<s.length(); i++)
    {
        m.insert(s[i]);
    }

    if(m.size() % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
        
    return 0;
}
