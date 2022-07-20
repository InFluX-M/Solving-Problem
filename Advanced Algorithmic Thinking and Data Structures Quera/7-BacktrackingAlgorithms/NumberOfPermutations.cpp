#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#define ll long long int
using namespace std;

vector<vector<int>> permutions;
void solve(vector<int> p);
int n;
int kAim;
int ans = 0;

int main()
{
    cin >> n >> kAim;
    vector<int> a;
    solve(a);
    
    for (int i = 0; i < permutions.size(); i++)
    {
        int m = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (permutions[i][j] > permutions[i][k]) m++;
            }
        }

        if (m == kAim) ans++;
    }

    cout << ans;
}

void solve(vector<int> p)
{
    if(p.size()==n)
    {
        permutions.push_back(p);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (find(p.begin(), p.end(), i) == p.end())
        {
            p.push_back(i);
            solve(p);
            p.pop_back();
        }
    }
}

