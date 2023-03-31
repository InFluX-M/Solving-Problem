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

int main()
{
    fastio;

    int r, c;
    cin >> r >> c;

    bool st[r + 2][c + 2];
    for (int i = 0; i < r + 2; i++)
        fill_n(st[i], c + 2, false);

    int n;
    cin >> n;

    int temp = n;
    while (temp--)
    {
        int x, y;
        cin >> x >> y;
        st[x][y] = true;
    }

    for (int k = 0; k < 9; k++)
    {
        int aim = 0;

        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (!st[i][j])
                    continue;
                int nAdj = (st[i][j - 1]) + (st[i][j + 1]) + (st[i - 1][j]) + (st[i + 1][j]) + (st[i + 1][j + 1]) + (st[i + 1][j - 1]) + (st[i - 1][j + 1]) + (st[i - 1][j - 1]);
                if (nAdj == k)
                    aim++;
            }
        }

        cout << aim << " ";
    }

    return 0;
}
