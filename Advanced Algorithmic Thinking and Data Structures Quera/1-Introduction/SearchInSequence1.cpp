#include <iostream>
using namespace std;

int main()
{
    int n, q;
    cin >> n;
    cin >> q;

    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    

    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        int num = 0;
        for (int j = 0; j < n; j++) if (a[j] < x) num++;

        cout << num << "\n";
    }
}