#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long int solve = arr[0];
    long long int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (solve < sum)
            solve = sum;

        if (sum <= 0)
        {
            sum = 0;
        }
    }

    return solve;
}

int main()
{
    int arr[] = {1, 2, 3, -2, 5};
    cout << maxSubarraySum(arr, 5);
    return 0;
}
