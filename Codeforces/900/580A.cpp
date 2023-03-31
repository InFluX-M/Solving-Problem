#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mxSubseq = 1;
    int currSubseq = 1;
    for(int i=1; i<n; i++)
    {
        if(a[i] >= a[i-1])
            currSubseq++;
        else
            currSubseq = 1;

        mxSubseq = max(mxSubseq, currSubseq);
    }

    cout << mxSubseq << endl;
    
    return 0;
}
