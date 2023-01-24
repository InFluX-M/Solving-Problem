#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool check(vector<ll> A, vector<ll> B, int N)
{
    unordered_map<ll, ll> mp1;
    unordered_map<ll, ll> mp2;

    for (int i = 0; i < N; i++)
    {
        mp1[A[i]]++;
    }
    for (int i = 0; i < N; i++)
    {
        mp2[B[i]]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (mp1[A[i]] != mp2[A[i]])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}
