#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define ll long long int

//مستطیل بد متوسط

int main()
{
    int n;
    cin >> n;

    ll nO = 0;
    for (ll i = 1; i <= floor(n / 3.0); i++)
    {
        int temp = (floor(n / 2.0) - (2 * i) + 1);
        ll lower = max(0, temp);
        ll upper = (floor((n - 3.0 * i) / 2.0));

        nO += (upper - lower + 1);
    }

    cout << nO % (1000000000 + 7);
}