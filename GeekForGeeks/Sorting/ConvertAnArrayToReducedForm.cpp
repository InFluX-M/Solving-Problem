#include <bits/stdc++.h>
using namespace std;

void convert(int arr[], int n)
{
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++)
        v.push_back(make_pair(arr[i], i));

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
        arr[v[i].second] = i;
        
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {10, 40, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    convert(arr, n);
    return 0;
}
