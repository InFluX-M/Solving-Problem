#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<pair<int, int>> a, vector<pair<int, int>> b, int aim, int l, int r, bool flg)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        int value = b[mid].first;

        if (value == aim)
            return mid;

        if (value > aim)
            return binarySearch(a, b, aim, l, mid - 1, flg);

        return binarySearch(a, b, aim, mid + 1, r, flg);
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a;
    vector<pair<int, int>> b;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, y));
        b.push_back(make_pair(x, y));
    }

    sort(a.begin(), a.end());

    sort(b.begin(), b.end(), [](auto &left, auto &right)
         { return left.second < right.second; });

    for (int i = 0; i < n; i++)
    {
        int idx = binarySearch(a, b, b[i].second, 0, n, false);
        if (idx > i)
        {
            cout << "Happy Alex";
            return 0;
        }
    }

    cout << "Poor Alex";
    return 0;
}
