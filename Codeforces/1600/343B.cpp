#include <bits/stdc++.h>
using namespace std;


void solve()
{
    string s;
    cin >> s;

    stack<char> st;

    for (char c : s)
    {
        bool flag = true;
        while (!st.empty() && st.top() == c)
        {
            st.pop();
            flag = false;
        }
        if (flag)
            st.push(c);
    }

    if (st.empty())
        cout << "Yes";
    else
        cout << "No";
}

int32_t main()
{
    int t = 1;
    while (t--)
        solve();

    return 0;
}
