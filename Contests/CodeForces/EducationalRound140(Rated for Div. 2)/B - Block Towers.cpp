#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
    int t;
    cin >>t ;
 
    while(t--)
    {
        vector<ll> a;
        int n;
        cin >> n;
 
        ll aim;
        cin >> aim;
 
        for (int i = 0; i < n-1; i++)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
 
        sort(a.begin(), a.end());
 
        for(int i=0; i<n-1; i++)
        {
            if(a[i] > aim)
            {
                aim += (a[i]-aim)/2 + (a[i]-aim)%2;
            }
        }
 
        cout << aim << "\n";
    }
 
    return 0;
}