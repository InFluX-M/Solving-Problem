#include <iostream>
using namespace std;

#define ll long long int

int main()
{
    int n;
    cin >> n;

    int nO = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int k = n - (i + j);
            if (k >= j && (i + j) > k) nO++;
        }

    cout << nO;
}