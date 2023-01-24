#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a = mergeSort(a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << k;
    return 0;
}
