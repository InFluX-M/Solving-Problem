#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vector_ll;
typedef vector<string> vector_string;
typedef vector<char> vector_char;
typedef vector<bool> vector_bool;
typedef vector<int> vector_int;

#define find_vec(vec, item, first_index, last_index) find(vec.begin() + first_index, vec.begin() + last_index + 1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin() + first_index, vec.begin() + last_index + 1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin() + first_index, vec.begin() + last_index + 1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin() + first_index, vec.begin() + last_index + 1, 0)

ll mod = (ll)(1e9 + 7);

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

int k = 0;

bool solve(vector<int> right, vector<int> left, int n, int sum, vector<bool> visit, vector<pair<int, int>> &a)
{
    bool flg = true;
    for (bool u : visit)
    {
        if (!u)
            flg = false;
    }
    if (flg)
    {
        k++;
        return true;
    }

    int sumLeft = 0;
    for (int u : left)
        sumLeft += u;

    int sumRight = 0;
    for (int u : right)
        sumRight += u;

    vector<int> ab;
    for (int i = 0; i < n; i++)
    {
        if (visit[i])
            continue;

        if (a[i].second == a[i].first + sumRight || a[i].second == sum - sumLeft)
        {
            visit[i] = true;
            right.push_back(a[i].first);
        }
        else if (a[i].second == a[i].first + sumLeft || a[i].second == sum - sumRight)
        {
            visit[i] = true;
            left.push_back(a[i].first);
        }
    }
    solve(right, left, n, sum, visit, a);
}

int main()
{
    int n;
    cin >> n;

    int sum = 0;

    vector<bool> visit(n, false);
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a.push_back(make_pair(u, v));

        sum += u;
    }

    vector<int> ab;
    for (int i = 0; i < n; i++)
    {
        if (a[i].second == sum || a[i].second == a[i].first)
        {
            ab.push_back(a[i].first);
            visit[i] = true;
        }
    }

    vector<int> right1, left1, right2, left2;
    right1.push_back(ab[0]);
    left1.push_back(ab[0]);

    right2.push_back(ab[1]);
    left2.push_back(ab[1]);

    solve(right1, left2, n, sum, visit, a);
    solve(right2, left1, n, sum, visit, a);

    cout << k;
    return 0;
}
