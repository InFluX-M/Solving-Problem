#include <iostream>
using namespace std;

int main()
{
    int nTest;
    cin >> nTest;

    for (int test = 1; test <= nTest; test++)
    {
        int nRow, nCollumn;
        cin >> nRow >> nCollumn;

        int row, collumn;
        cin >> row >> collumn;

        char** grid = new char* [nRow];
        for (int i = 0; i < nRow; i++) grid[i] = new char[nCollumn];

        int state;
        int nBlack = 0;

        for (int i = 0; i < nRow; i++)
            for (int j = 0; j < nCollumn; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'B') nBlack++;
            }

        bool flag = false;

        if (nBlack == 0)
        {
            cout << -1;
            flag = true;
        }
        else if (grid[row - 1][collumn - 1] == 'B')
        {
            cout << 0;
            flag = true;
        }
        else
        {

            for (int i = 0; i < nCollumn; i++) if (grid[row - 1][i] == 'B')
            {
                cout << 1;
                flag = true;
                break;
            }

            if (!flag)
            {
                for (int i = 0; i < nRow; i++) if (grid[i][collumn - 1] == 'B')
                {
                    cout << 1;
                    flag = true;
                    break;
                }
            }
 
        }

        if (!flag) cout << 2;

        for (int i = 0; i < nRow; i++) delete[] grid[i];
        cout << "\n";
    }
}

