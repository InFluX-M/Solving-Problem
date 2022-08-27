#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#define ll long long int
using namespace std;


bool solve();
bool validate(int row, int collumn, int value);
int grid[9][9];

int main()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) cin >> grid[i][j];

    if (solve())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists";
    }
    

}

bool validate(int row, int collumn, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (value == grid[i][collumn]) return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (value == grid[row][i]) return false;
    }

    int startRow = row - row % 3,
        startCol = collumn - collumn % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == value)
                return false;

    return true;
}
string find()
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                return to_string(i) + " " + to_string(j);
            }
        }
    }

    return "";

}

bool solve()
{
    int r, c;
    string s = find();
    if (find() == "")
    {
        return true;
    }
    else
    {
        r = int(s[0]) - 48;
        c = int(s[2]) - 48;
    }


    for (int i = 1; i <= 9; i++)
    {
        bool valid = validate(r, c, i);

        if (valid)
        {
            grid[r][c] = i;
            if (solve()) return true;
            grid[r][c] = 0;
        }
    }

    return false;
}
