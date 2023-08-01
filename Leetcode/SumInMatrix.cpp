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

int matrixSum(vector<vector<int>> &nums)
{
    vector<priority_queue<int>> pqs(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        for (int u : nums[i])
            pqs[i].push(u);
    }

    int res = 0;
    for (int i = 0; i < nums[0].size(); i++)
    {
        int aim = INT_MIN;
        for (int j = 0; j < nums.size(); j++)
        {
            aim = max(aim, pqs[j].top());
            pqs[j].pop();
        }
        res += aim;
    }

    return res;
}

int main()
{
    fastio;
    vector<vector<int>> s = {{7, 2, 1}, {6, 4, 2}, {6, 5, 3}, {3, 2, 1}};
    cout << matrixSum(s);
    return 0;
}
