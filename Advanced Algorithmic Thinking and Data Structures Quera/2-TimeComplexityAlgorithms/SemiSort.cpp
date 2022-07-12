#include <iostream>
using namespace std;

#define ll long long int

int main()
{
    int n;
    cin >> n;
    ll* a = new ll[n];

    int nF = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != i + 1) nF++;
    }

    if (nF == 2) cout << "YES";
    else cout << "NO";

    delete[] a;
}
