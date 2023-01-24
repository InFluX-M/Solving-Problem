#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int low, int high, int* a)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(int low, int high, int a[])
{
    if (low < high)
    {
        int q = partition(low, high, a);
        quickSort(low, q - 1, a);
        quickSort(q + 1, high, a);
    }
}

int main()
{
    int a[] = {5, 6, 9, 2, 1, 7};
    quickSort(0, 5, a);

    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
