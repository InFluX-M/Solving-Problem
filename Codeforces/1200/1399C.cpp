#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll mod = 1e9 + 7;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define F first
#define S second

ll mul(ll a, ll b)
{
    return (a % mod) * (b % mod) % mod;
}

ll min(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll sum(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    fastio

        int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        unordered_map<int, int> m;

        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;

            if (a[i] > mx1)
            {
                mx2 = mx1;
                mx1 = a[i];
            }
            else if (a[i] > mx2)
            {
                mx2 = a[i];
            }
        }

        int aim = 0;
        for (int s = 1; s <= mx1 + mx2; s++)
        {
            int cnt = 0;
            unordered_map<int, int> temp = m;
            for (int num : a)
            {
                if(temp[num] == 0) continue;
                if (num == s - num && temp[s - num] > 1)
                {
                    cnt++;
                    temp[num] -= 2;
                }
                else if (num != s - num && temp[s - num] > 0)
                {
                    cnt++;
                    temp[s - num]--;
                    temp[num]--;
                }
            }
            aim = max(aim, cnt);
        }

        cout << aim << endl;
    }
    return 0;
}
