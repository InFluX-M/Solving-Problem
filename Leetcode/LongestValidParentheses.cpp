#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    stack<int> st;
    int len = 0, mxlen = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            st.push(c);
            len++;
        }
        else
        {
            if (st.top() != '(')
            {
                mxlen = max(mxlen, len);
                while (!st.empty())
                {
                    st.pop();
                }
            }
            else
        }
    }
}

int32_t main()
{
    int t = 1;
    while (t--)
        solve();

    return 0;
}
