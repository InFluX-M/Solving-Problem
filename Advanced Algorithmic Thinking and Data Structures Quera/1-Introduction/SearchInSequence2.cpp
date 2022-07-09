#include <iostream>
using namespace std;

//جست‌وجو در دنباله 2

int main()
{
    int n, q;
    cin >> n;
    cin >> q;

    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int M = 0;
    for (int i = 0; i < n; i++) if (a[i] > M) M = a[i];

    int* c = new int[M];
    for (int i = 0; i < M; i++) c[i] = 0;
    
    for (int i = 0; i < n; i++) c[a[i] - 1]++;
    

    int* p = new int[M];
    for (int i = 0; i < M; i++) p[i] = 0;
    
    for (int i = 1; i < M; i++) p[i] = c[i - 1] + p[i - 1];

    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;

        if (x > M) cout << n;
        else cout << p[x - 1];

        cout << "\n";
    }

}