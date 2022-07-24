#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int* set = new long long int[n];
    for (long long int i = 0; i < n; i++) cin >> set[i];

    long long int sumT = 0;
    for (int i = 0; i < n; i++) sumT += set[i];

    long long int sumMid = 0;
    for (long long int mask = 0; mask < (1 << n); mask++) {
        long long int sum = 0;
        for (long long int i = 0; i < n; i++)
            if (mask & (1 << i))
            {
                sum += set[i];
            }
        if ((abs(sumT / 2 - sumMid)) > abs(sumT / 2 - sum)) sumMid = sum;
    }

    cout << abs(sumT - 2 * sumMid);

}