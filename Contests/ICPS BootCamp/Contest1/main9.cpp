#include <bits/stdc++.h>
using namespace std;

void dfs(int u, bool mark[], vector<vector<int>> &adj, unordered_set<int> &comp)
{
    mark[u] = true;
    comp.insert(u);

    for (int v : adj[u])
        if (!mark[v])
            dfs(v, mark, adj, comp);
}

void dfsStack(int u, bool mark[], vector<vector<int>> &adj, stack<int> &st)
{
    mark[u] = true;

    for (int v : adj[u])
        if (!mark[v])
            dfsStack(v, mark, adj, st);

    st.push(u);
}

vector<unordered_set<int>> scc(int n, vector<vector<int>> &adj, vector<vector<int>> &adjT)
{
    vector<unordered_set<int>> components;
    stack<int> st;

    bool *mark = new bool[n];
    fill_n(mark, n, false);

    for (int i = 0; i < n; i++)
        if (mark[i] == false)
            dfsStack(i, mark, adj, st);

    fill_n(mark, n, false);

    while (st.empty() == false)
    {
        int u = st.top();
        st.pop();

        if (mark[u] == false)
        {
            unordered_set<int> comp;
            dfs(u, mark, adjT, comp);
            components.push_back(comp);
        }
    }

    return components;
}

void slv(int u, bool mark[], vector<vector<int>> &adj)
{
    mark[u] = true;

    for (int v : adj[u])
        if (!mark[v])
            slv(v, mark, adj);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> adjT(n, vector<int>());

    vector<vector<int>> statue(n, vector<int>(n, false));

    for (int i = 0; i < n; i++)
    {
        int nAdj;
        cin >> nAdj;
        while (nAdj--)
        {
            int t;
            cin >> t;
            statue[i][t - 1] = true;
            adj[i].push_back(t - 1);
            adjT[t - 1].push_back(i);
        }
    }

    vector<unordered_set<int>> Scc = scc(n, adj, adjT);
    vector<vector<int>> adjS(Scc.size(), vector<int>());

    for (int i = 0; i < Scc.size(); i++)
    {
        for (int j = 0; j < Scc.size(); j++)
        {
            bool flag = false;
            if (i == j)
                continue;
            for (int u : Scc[i])
            {
                for (int v : Scc[j])
                {
                    if (statue[u][v])
                    {
                        adjS[i].push_back(j);
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
    }

    int cnt = 0;
    bool *visit = new bool[Scc.size()];
    for (int i = 0; i < Scc.size(); i++)
    {
        if(!visit[i])
        {
            slv(i, visit, adjS);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
