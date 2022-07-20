#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#define ll long long int
using namespace std;

int ans = 0;
int n;
vector<vector<ll>> numbers;
void solve(int row, vector<ll> number);

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        vector<ll> temp;
        ll nNum;
        cin >> nNum;

        for (int j = 0; j < nNum; j++)
        {
            ll t;
            cin >> t;
            temp.push_back(t);
        }

        numbers.push_back(temp);
    }

    vector<ll> temp;
    solve(0, temp);

    cout << ans;
}

void solve(int row, vector<ll> number)
{
    if (row == n)
    {
        if (number.size() == n) ans++;
        return;
    }

    for (int i = 0; i < numbers[row].size(); i++)
    {
        if (find(number.begin(), number.end(), numbers[row][i]) == number.end())
        {
            number.push_back(numbers[row][i]);
            solve(row + 1, number);
            number.pop_back();
        }
    }
}