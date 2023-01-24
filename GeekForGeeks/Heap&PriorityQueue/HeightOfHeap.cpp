#include <bits/stdc++.h>
using namespace std;

int heapHeight(int N)
{
    int low = 1;
    int up = N + 1;

    int minChange = 1000000000;
    int aim = 0;

    while (low < up)
    {
        int mid = (low + up) / 2;

        if (pow(2, mid) - 1 == N)
        {
            aim = mid;
            break;
        }
        else if (pow(2, mid) - 1 < N)
        {
            low = mid + 1;
        }
        else if (pow(2, mid) - 1 > N)
        {
            up = mid - 1;
            if (minChange > pow(2, mid) - 1 - N)
            {
                minChange = pow(2, mid) - 1 - N;
                aim = mid;
            }
        }
    }

    return aim;
}

int main()
{

    cout << heapHeight(1)-1;
    return 0;
}
