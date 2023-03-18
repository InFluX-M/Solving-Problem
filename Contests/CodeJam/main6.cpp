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

void dfs(int u, vector<bool> &visit, vector<vector<int>> &adj, unordered_set<int> &comp)
{
    visit[u] = true;
    comp.insert(u);

    for (int v : adj[u])
    {
        if (!visit[v])
        {
            dfs(v, visit, adj, comp);
        }
    }
}

int main()
{
    int n, m, p;
    cin >> n >> m >> p;

    vector<vector<int>> ADJ(n, vector<int>());
    map<int, int> edge;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ADJ[u].push_back(v);
        ADJ[v].push_back(u);

        edge[u]++;
        edge[v]++;
    }

    vector<pair<bool, unordered_set<int>>> component;
    int nC = 0;
    vector<bool> visit(n, false);
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> comp;
        if (!visit[i])
        {
            dfs(i, visit, ADJ, comp);
            if (i == 0 && visit[1])
            {
                cout << "First";
                return 0;
            }
            component.push_back(make_pair(false, comp));
        }
    }

    vector<int> edgeComp(component.size(), 0);
    int i = 0;
    for (pair<bool, unordered_set<int>> a : component)
    {
        int s = 0;
        for (int u : a.second)
        {
            s += edge[u];
        }
        edgeComp[i++] = s / 2;
    }

    int N = component.size();
    i = 0;
    while (i < (N - 2))
    {
        int sMax = 0, s = 0, idx = 0;
        for (int j = 2; j < N; j++)
        {
            s = 0;
            if (component[j].first)
                continue;

            s += (component[j].second.size() * component[i % 2].second.size()) + (component[j].second.size() * (component[j].second.size() - 1) / 2 - edgeComp[j]);

            if (s > sMax)
            {
                sMax = s;
                idx = j;
            }
        }

        component[idx].first = true;

        for (int u : component[idx].second)
            component[i % 2].second.insert(u);

        edgeComp[i % 2] += edgeComp[idx];
        i++;
    }

    int t1 = (component[0].second.size()) * (component[0].second.size() - 1) / 2 - edgeComp[0];
    int t2 = (component[1].second.size()) * (component[1].second.size() - 1) / 2 - edgeComp[1];

    if (t1 > t2)
        cout << "First";
    else
        cout << "Second";

    return 0;
}
