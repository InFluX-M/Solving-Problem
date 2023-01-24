#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
 
int main()
{
    ll t;
    cin >>t;
 
    while(t--)
    {
        ll n;
        map<ll, vector<int>> slv;
 
        cin >> n;
        vector<ll> a;
        for(int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.push_back(x);
            slv[x].push_back(i+1);
        }
 
        sort(a.begin(), a.end());
        ll minA = a[0];
        ll prev = a[0];
        ll nD = 0;
        vector<pair<ll, ll>> res;
        for(int i = 1; i < n; i++)
        {
            if(a[i] != minA)
            {
                if(prev == a[i]) nD++;
                else
                {
                    prev = a[i];
                    nD = 0;
                }
                int tmp1 = a[i]/minA + 1;
 
                res.push_back(make_pair(slv[a[i]][nD], minA*tmp1-a[i]));
                minA = minA*tmp1;
            }
        }
 
        cout << res.size() << "\n";
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i].first << " " << res[i].second << "\n";
        }
    }
    return 0;
}