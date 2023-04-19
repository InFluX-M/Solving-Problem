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

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

queue<int> q;

void push(int x)
{
    q.push(x);
}

int pop()
{
    if(q.empty()) return -1;

    int size = q.size();
    while (size > 1)
    {
        q.push(q.front());
        q.pop();
        size--;
    }

    int u = q.front();
    q.pop();

    return u;
    
}

int main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        int o;
        cin >> o;

        if(o == 1)
        {
            cout << pop() << endl;
        }
        else 
        {
            int x;
            cin >> x;
            push(x);
        }
    }
    
    return 0;
}
