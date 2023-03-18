#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vector_ll;
typedef vector<string> vector_string;
typedef vector<char> vector_char;
typedef vector<bool> vector_bool;
typedef vector<int> vector_int;

const int maxN = 1e6 + 5;
int *primes;
int *lprime;

int main()
{
    primes = new int[1000000 + 1];
    lprime = new int[1000000 + 1];

    lprime[0] = 1;
    lprime[1] = 1;

    fill_n(primes, maxN, 1);

    primes[0] = 0;
    primes[1] = 0;

    for (int i = 2; i < maxN; i++)
    {
        if (!primes[i])
            continue;

        lprime[i] = i;
        for (int j = 2 * i; j < maxN; j += i)
        {
            primes[j] = 0;
            lprime[j] = i;
        }
    }

    ll count[maxN];
    count[0] = 0;
    count[1] = 0;

    ll pS[maxN];
    pS[0] = 0;
    pS[1] = 0;

    for (int i = 2; i < maxN; i++)
    {
        count[i] = count[i / lprime[i]] + 1;
        pS[i] = pS[i - 1] + count[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << pS[a] - pS[b] << "\n";
    }

    return 0;
}
