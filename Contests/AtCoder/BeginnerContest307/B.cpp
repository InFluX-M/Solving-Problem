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

bool palindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i])
            return false;

    return true;
}

int main()
{
    fastio;
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    bool f = false;
    for (int i = 0; i < n && !f; i++)
    {
        for (int j = 0; j < n && !f; j++)
        {
            if (i == j)
                continue;

            string newS = s[i] + s[j];
            if (palindrome(newS))
                f = true;
        }
    }

    if (f)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
