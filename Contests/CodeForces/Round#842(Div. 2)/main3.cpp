#include <bits/stdc++.h>
using namespace std;
typedef multimap<int, int>::iterator ity;

vector<int> countingSort(vector<int> a)
{
    int n = a.size();
    vector<int> count(n);
    vector<int> output(n);

    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    for (int i = 1; i < n; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    return output;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }

        int count[n];
        bool flag = true;
        vector<int> b = a;
        sort(a.begin(), a.end());

        unordered_map<int, bool> p;
        unordered_map<int, bool> q;

        int pArray[n];
        int qArray[n];
        int c = 0;

        int iP = 1, iQ = 1;
        for (int i = 0; i < a.size(); i++)
        {
            if (p[a[i]] && q[a[i]])
            {
                flag = false;
                break;
            }
            else if (p[a[i]])
            {
                if (iP >= a[i])
                {
                    flag = false;
                    break;
                }
                else
                {
                    qArray[c] = a[i];
                    pArray[c] = iP;
                    c++;
                    q[a[i]] = true;
                    p[iP] = true;
                    iP++;
                }
            }
            else if (q[a[i]])
            {
                if (iQ >= a[i])
                {
                    flag = false;
                    break;
                }
                else
                {
                    pArray[c] = a[i];
                    qArray[c] = iQ;
                    c++;
                    p[a[i]] = true;
                    q[iQ] = true;
                    iQ++;
                }
            }
            else
            {
                if (iQ >= a[i] && iP >= a[i])
                {
                    pArray[c] = a[i];
                    qArray[c] = a[i];
                    c++;
                    p[a[i]] = true;
                    q[a[i]] = true;
                }
                else if (iQ >= a[i])
                {
                    pArray[c] = iP;
                    qArray[c] = a[i];
                    c++;
                    q[a[i]] = true;
                    p[iP] = true;
                    iP++;
                }
                else if (iP >= a[i])
                {
                    pArray[c] = a[i];
                    qArray[c] = iQ;
                    c++;
                    p[a[i]] = true;
                    q[iQ] = true;
                    iQ++;
                }
                else
                {
                    pArray[c] = a[i];
                    qArray[c] = iQ;
                    c++;
                    p[a[i]] = true;
                    q[iQ] = true;
                    iQ++;
                }
            }
        }

        if (flag)
        {
            multimap<int, int> indexes;
            for (int i = 0; i < n; i++)
            {
                indexes.insert({max(pArray[i], qArray[i]), i});
            }

            int aimP[n];
            int aimQ[n];

            for (int i = 0; i < n; i++)
            {
                int index = (*indexes.find(b[i])).second;
                aimP[i] = pArray[index];
                aimQ[i] = qArray[index];

                pair<ity, ity> iterpair = indexes.equal_range(b[i]);

                // Erase (b,15) pair
                //
                ity it = iterpair.first;
                for (; it != iterpair.second; ++it)
                {
                    if (it->second == index)
                    {
                        indexes.erase(it);
                        break;
                    }
                }
            }
            cout << "YES"
                 << "\n";
            for (int i = 0; i < c; i++)
            {
                cout << aimP[i] << " ";
            }
            cout << "\n";
            for (int i = 0; i < c; i++)
            {
                cout << aimQ[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
    return 0;
}
