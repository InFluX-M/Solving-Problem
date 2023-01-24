#include <bits/stdc++.h>
using namespace std;

vector<int> assign(int arr[], int n)
{
    vector<int> v;

    return v;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (arr[i] > arr[i - 1])
                swap(arr[i - 1], arr[i]);
        }
        // if index is odd
        else
        {
            if (arr[i] < arr[i - 1])
                swap(arr[i - 1], arr[i]);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     v.push_back(arr[i]);
    // }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // 8 5 2 3 4 1 6 7
    return 0;
}
