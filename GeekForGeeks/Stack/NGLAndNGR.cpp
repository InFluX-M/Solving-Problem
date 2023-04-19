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

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2")

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

vector<int> NGE(vector<int> &a, int n)
{
    vector<int> res(n, 0);

    stack<int> s;
    s.push(0);
    res[0] = 0;

    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    return res;
}

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<int> a(n), ans;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ans = NGE(a, n);
    reverse(all(a));
    vector<int> temp = NGE(a, n);

    int target = 0;
    for (int i = 0; i < n; i++)
        target = max(target, (ans[i] + 1) * (n - a[n - 1 - i]));

    cout << target;
    return 0;
}
