#include <bits/stdc++.h>
using namespace std;

void rearrange(long long *arr, int n)
{
    int a[n];
    int idxMax = n-1, idxMin = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            a[i] = arr[idxMax--];
        }
        else
        {
            a[i] = arr[idxMin++];
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    rearrange(arr, n);
    return 0;
}
