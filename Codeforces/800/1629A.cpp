#include <iostream>

using namespace std;

void sort2Array(int n, int* array1, int* array2);

int main()
{
    int nTest;
    cin >> nTest;

    for (int counter = 1; counter <= nTest; counter++)
    {
        int n, nowRam;
        cin >> n >> nowRam;

        int* reqRam = new int[n];
        int* addRam = new int[n];

        for (int i = 0; i < n; i++) cin >> reqRam[i];
        for (int i = 0; i < n; i++) cin >> addRam[i];

        sort2Array(n, reqRam, addRam);

        int indexRam = 0;

        while (nowRam >= reqRam[indexRam] && indexRam < n)
        {
            nowRam += addRam[indexRam];

            indexRam++;
        }

        cout << nowRam << "\n";

        delete[] reqRam;
        delete[] addRam;
    }
}

void sort2Array(int n,int* array1, int* array2)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool bubbleFound = false;
        
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array1[j] > array1[j + 1])
            {
                int temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;

                temp = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = temp;

                bubbleFound = true;
            }
        }

        if (!bubbleFound) break;
    }
}
