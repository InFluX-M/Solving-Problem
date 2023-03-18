#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    vowels.insert('y');
    vowels.insert('A');
    vowels.insert('E');
    vowels.insert('I');
    vowels.insert('O');
    vowels.insert('U');
    vowels.insert('Y');

    string s;
    cin >> s;

    string s1 = "";
    for(int i=0; i<s.length(); i++)
    {
        if(vowels.find(s[i]) == vowels.end())
        {
            s1.push_back('.');
            if(s[i] >= 'A' && s[i] <= 'Z')
                s1.push_back(s[i] + 32);
            else
                s1.push_back(s[i]);
        }
    }

    cout << s1 << endl;
    return 0;
}
