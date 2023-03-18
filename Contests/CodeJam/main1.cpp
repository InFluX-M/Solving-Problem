#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vector_ll;
typedef vector<string> vector_string;
typedef vector<char> vector_char;
typedef vector<bool> vector_bool;
typedef vector<int> vector_int;

int main()
{
    int n;
    cin >> n;

    map<int, bool> statue;

    queue<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push(make_pair(i, t));
    }

    int b[n];

    while (!a.empty())
    {
        pair<int, int> t = a.front();
        if (!statue[t.second])
        {
            statue[t.second] = true;
            b[t.first] = t.second;
            a.pop();
        }
        else
        {
            a.pop();
            a.push(make_pair(t.first, t.second + 1));
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}
