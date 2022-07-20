#include <iostream>
#include <vector>
using namespace std;
vector<int> mergerSort(vector<vector<int>> a);


int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> a;

    for (int i = 0; i < k; i++)
    {
        vector<int> temp;

        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            temp.push_back(t);
        }

        a.push_back(temp);
    }

    vector<int> finalAim = mergerSort(a);
    for (int i = 0; i < n*k; i++)
    {
        cout << finalAim[i] << " ";
    }

}

vector<int> mergerSort(vector<vector<int>> a)
{
    vector<int> t;
    if (a.size() == 0) return t;
    if (a.size() == 1) return a[0];

    vector<vector<int>> a1;
    vector<vector<int>> a2;

    for (int i = 0; i < a.size() / 2; i++) a1.push_back(a[i]);
    for (int i = a.size() / 2; i < a.size(); i++) a2.push_back(a[i]);

    vector<int> aim1 = mergerSort(a1);
    vector<int> aim2 = mergerSort(a2);

    vector<int> finalAim;
    int i = 0;
    int j = 0;

    while (i <= aim1.size() - 1 && j <= aim2.size() - 1)
    {

        if (aim1[i] > aim2[j])
        {
            finalAim.push_back(aim2[j]);
            j++;
        }
        else
        {
            finalAim.push_back(aim1[i]);
            i++;
        }
    }

    while (i <= aim1.size() - 1)
    {
        finalAim.push_back(aim1[i]);
        i++;

    }
    while (j <= aim2.size() - 1)
    {
        finalAim.push_back(aim2[j]);
        j++;
    }

    return finalAim;

}