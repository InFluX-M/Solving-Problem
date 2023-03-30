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

string infixToPostfix(string infix)
{
    unordered_map<char, int> op;
    op['+'] = 1;
    op['-'] = 1;
    op['*'] = 2;
    op['/'] = 2;
    op['^'] = 3;
    op['('] = 4;
    op[')'] = 4;

    stack<char> s;

    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        if (op.find(infix[i]) != op.end())
        {
            if (infix[i] == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    postfix.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }
            else if (infix[i] == '(')
                s.push('(');
            else
            {
                while (!s.empty() && s.top() != '(' && s.top() != ')' && op[s.top()] >= op[infix[i]])
                {
                    postfix.push_back(s.top());
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
        else
            postfix.push_back(infix[i]);
    }

    while (!s.empty())
    {
        postfix.push_back(s.top());
        s.pop();
    }

    return postfix;
}

int main()
{
    fastio;

    string in;
    cin >> in;

    cout << infixToPostfix(in);
    return 0;
}
