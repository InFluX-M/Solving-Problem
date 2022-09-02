#include <iostream>

using namespace std;

int main()
{
    int nTest;
    cin >> nTest;

    for (int counter = 1; counter <= nTest; counter++)
    {
        int n;
        cin >> n;

        int* number1 = new int[n];
        int* number2 = new int[n];

        for (int i = 0; i < n; i++) cin >> number1[i];
        for (int i = 0; i < n; i++) cin >> number2[i];

        int max1 = 0;
        int max2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (number1[i] < number2[i])
            {
                if (max1 < number1[i]) max1 = number1[i];
                if (max2 < number2[i]) max2 = number2[i];
            }
            else
            {
                if (max1 < number2[i]) max1 = number2[i];
                if (max2 < number1[i]) max2 = number1[i];
            }   
        }

        cout << max1 * max2 << "\n";

        delete[] number1;
        delete[] number2;

    }
}
