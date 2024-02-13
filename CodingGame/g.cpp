#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int width;
    int height;
    int my_id;
    cin >> width >> height >> my_id;
    cin.ignore();

    // game loop
    while (1)
    {
        vector<string> grid;
        for (int i = 0; i < height; i++)
        {
            string row;
            cin >> row;
            cin.ignore();
            grid.push_back(row);
        }

        vector<vector<tuple<int, int, int>>> bombs(2, vector<tuple<int, int, int>>());
        vector<tuple<int, int, int>> players(2, tuple<int, int, int>());

        int entities;
        cin >> entities;
        cin.ignore();
        for (int i = 0; i < entities; i++)
        {
            int entity_type;
            int owner;
            int x;
            int y;
            int param_1;
            int param_2;
            cin >> entity_type >> owner >> x >> y >> param_1 >> param_2;
            cin.ignore();

            if (entity_type)
                bombs[owner].push_back(make_tuple(x, y, param_1));
            else
                players[owner] = make_tuple(x, y, param_1);
        }

        vector<vector<int>> ngrid(height, vector<int>(width, 0));
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (grid[i][j] == '0')
                    ngrid[i][j] = 1;
            }
        }

        for (tuple<int, int, int> t : bombs[0])
        {
            int x = get<0>(t);
            int y = get<1>(t);

            for (int i = 0; i < 3 && x + i < width; i++)
                ngrid[x + i][y] = 0;

            for (int i = 0; i < 3 && x - i >= 0; i++)
                ngrid[x - i][y] = 0;

            for (int i = 0; i < 3 && y + i < height; i++)
                ngrid[x][y + i] = 0;

            for (int i = 0; i < 3 && y - i >= 0; i++)
                ngrid[x][y - i] = 0;
        }

        for (tuple<int, int, int> t : bombs[1])
        {
            int x = get<0>(t);
            int y = get<1>(t);

            for (int i = 0; i < 3 && x + i < width; i++)
                ngrid[x + i][y] = 0;

            for (int i = 0; i < 3 && x - i >= 0; i++)
                ngrid[x - i][y] = 0;

            for (int i = 0; i < 3 && y + i < height; i++)
                ngrid[x][y + i] = 0;

            for (int i = 0; i < 3 && y - i >= 0; i++)
                ngrid[x][y - i] = 0;
        }

        int xA = 2, yA = 2, res = 0;
        vector<vector<int>> point(height, vector<int>(width, 0));
        for (int x = 2; x < height - 2; x++)
        {
            for (int y = 2; y < width - 2; y++)
            {
                int value = 0;
                for (int i = 0; i < 3 && x + i < width; i++)
                    value += ngrid[x + i][y];

                for (int i = 0; i < 3 && x - i >= 0; i++)
                    value += ngrid[x - i][y];

                for (int i = 0; i < 3 && y + i < height; i++)
                    value += ngrid[x][y + i];

                for (int i = 0; i < 3 && y - i >= 0; i++)
                    value += ngrid[x][y - i];

                point[x][y] = value;

                if (value > res)
                {
                    res = value;
                    xA = x;
                    yA = y;
                }
            }
        }

        cout << "BOMB " << xA << ' ' << yA << endl;
    }
}