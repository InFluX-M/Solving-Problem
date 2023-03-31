#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int m = log2(1.0*b/a) / log2(3.0/2);

    if(m == ceil(log2(1.0*b/a) / log2(3.0/2))) cout << m+1;
    else cout << ceil(log2(1.0*b/a) / log2(3.0/2));

    return 0;
}
