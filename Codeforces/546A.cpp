#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n, w;
    cin >> k >> n >> w;
    int aim = (((w*(w+1)/2) * k) > n )? ((w*(w+1)/2) * k) - n : 0;
    cout << aim;
    return 0;
}
