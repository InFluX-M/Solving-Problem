#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;
#define nl "\n"
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
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

ll modOp(ll a, ll b, int op)
{
    switch (op)
    {
    case 0:
        return ((a % MOD) + (b % MOD)) % MOD;
    case 1:
        return ((a % MOD) - (b % MOD) + MOD) % MOD;
    case 2:
        return (a % MOD) * (b % MOD) % MOD;
    }
}

#define HOOF 0
#define PAPER 1
#define SCISSORS 2

void solve()
{
    int n, k;
    cin >> n >> k;

    vi s(n);
    int nP = 0, nH = 0, nS = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        if (c == 'P')
        {
            nP++;
            s[i] = PAPER;
        }
        if (c == 'H')
        {
            nH++;
            s[i] = HOOF;
        }
        if (c == 'S')
        {
            nS++;
            s[i] = SCISSORS;
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(3, 0)));

    for (int i = 1; i < k; i++)
    {
        dp[0][i][0] = 1 ;
        dp[0][i][1] = 1;
        dp[0][i][2] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 1)
        {
            nP++;
        }
        if (s[i] == 0)
        {
            nH++;
        }
        if (s[i] == 2)
        {
            nS++;
        }
        dp[i][0][0] = nS;
        dp[i][0][1] = nH;
        dp[i][0][2] = nP;
    }
    

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j][0] = max(dp[i-1][j-1])
        }
    }
}

int32_t main()
{
    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
