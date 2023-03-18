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

int LCSub(string s, string p)
{
    int m = s.size();
    int n = p.size();

    int LCS[m + 1][n + 1];
    int lcs = 0;

    for (int i = 0; i <= m; i++)
        LCS[i][0] = 0;
    
    for (int i = 0; i <= n; i++)
        LCS[0][i] = 0;
    

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == p[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                lcs = max(lcs, LCS[i][j]);
            }
            else
                LCS[i][j] = 0;
        }
    }

    return lcs;
}

int n;
int findV(bool uVisit[], int weights[])
{
    int idx = -1;
    int mW = 0;

    for (int i = 0; i < n; i++)
    {
        if (!uVisit[i] && weights[i] > mW)
        {
            mW = weights[i];
            idx = i;
        }
    }
    return idx;
}

int maxST(int **graph)
{
    bool uVisit[n];
    fill_n(uVisit, n, false);

    int weights[n];
    fill_n(weights, n, 0);

    weights[0] = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        int maxVertexIndex = findV(uVisit, weights);
        uVisit[maxVertexIndex] = true;

        for (int j = 0; j < n; j++)
        {
            if (uVisit[j] == false)
            {
                if (graph[j][maxVertexIndex] > weights[j])
                {
                    weights[j] = graph[j][maxVertexIndex];
                }
            }
        }
    }

    int MST = 0;
    for (int i = 1; i < n; i++)
    {
        MST += weights[i];
    }

    return MST;
}

int main()
{
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int **adj = new int *[n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int lcs = LCSub(s[i], s[j]);
            adj[i][j] = lcs;
            adj[j][i] = lcs;
        }
    }

    cout << maxST(adj);
    return 0;
}
