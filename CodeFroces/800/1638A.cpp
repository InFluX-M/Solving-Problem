#include <iostream>

using namespace std;

int sequentialSearch(int permutation[], int aim, int n);
void reversePermutation(int permutation[], int first, int last);

int main()
{
    int nTest;
    cin >> nTest;

    for (int i = 1; i <= nTest; i++)
    {
        int n;
        cin >> n;

        int* permutation = new int[n];

        for (int i = 0; i < n; i++) cin >> permutation[i];

        for (int i = 0; i < n; i++)
        {
            bool flag = false;

            if (permutation[i] != i + 1)
            {
                int indexMin = sequentialSearch(permutation, i + 1, n);
                reversePermutation(permutation, i, indexMin);

                flag = true;
            }

            if (flag) break;
        }

        for (int i = 0; i < n; i++) cout << permutation[i] << " ";

        cout << "\n";

        delete[] permutation;
    }
   
}

int sequentialSearch(int permutation[], int aim, int n)
{
    for (int i = 0; i < n; i++) if (aim == permutation[i]) return i;

    return -1;
}
void reversePermutation(int permutation[], int first, int last)
{
    for (int i = first; i <= (first + last) / 2; i++)
    {
        int temp = permutation[i];
        permutation[i] = permutation[last + first - i];
        permutation[last + first - i] = temp;
    }
}