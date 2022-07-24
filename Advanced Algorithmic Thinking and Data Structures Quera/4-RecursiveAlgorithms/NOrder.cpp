#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long int
void solve(vector<ll> a);

vector<vector<ll>> aim;

int n;

int main()
{
    cin >> n;
    vector<ll> a;
    solve(a);
    
    for (int i = 0; i < pow(n,n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << aim[i][j] << " ";
        }

        cout << "\n";
    }
}

void solve(vector<ll> a)
{
    if (a.size() == n)
    {
        aim.push_back(a);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
        solve(a);
        a.pop_back();
    }

}

