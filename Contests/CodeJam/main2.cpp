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

int main()
{
    pair<int, int> a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    set<string> s1;
    if (a.first == b.first)
    {
        if (a.second > b.second)
        {
            if (c.second <= b.second)
                cout << "YES";
            else
                cout << "NO";
        }
        else if (a.second < b.second)
        {
            if (c.second >= b.second)
                cout << "YES";
            else
                cout << "NO";
        }
    }
    else if (a.second == b.second)
    {
        if (a.first > b.first)
        {
            if (c.first <= b.first)
                cout << "YES";
            else
                cout << "NO";
        }
        else if (a.first < b.first)
        {
            if (c.first >= b.first)
                cout << "YES";
            else
                cout << "NO";
        }
    }
    else
    {
        if (a.second < b.second && a.first < b.first)
        {
            if (b.first == c.first && c.second > b.second)
                cout << "YES";
            else if (b.second == c.second && c.first > b.first)
                cout << "YES";
            else
                cout << "NO";
        }
        else if (a.second < b.second && a.first > b.first)
        {
            if (b.first == c.first && c.second > b.second)
                cout << "YES";
            else if (b.second == c.second && c.first < b.first)
                cout << "YES";
            else
                cout << "NO";
        }
        else if (a.second > b.second && a.first < b.first)
        {
            if (b.first == c.first && c.second < b.second)
                cout << "YES";
            else if (b.second == c.second && c.first > b.first)
                cout << "YES";
            else
                cout << "NO";
        }
        else if (a.second > b.second && a.first > b.first)
        {
            if (b.first == c.first && c.second < b.second)
                cout << "YES";
            else if (b.second == c.second && c.first < b.first)
                cout << "YES";
            else
                cout << "NO";
        }
    }

    return 0;
}
