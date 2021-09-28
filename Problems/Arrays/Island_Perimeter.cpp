#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>> &grid)
{
    int blocks = 0, neighbours = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                blocks++;
                if (i != 0 && grid[i - 1][j] == 1)
                    neighbours++; // left neighbours
                if (j != 0 && grid[i][j - 1] == 1)
                    neighbours++; // down neighbours
            }
        }
    }
    return 4 * blocks - neighbours * 2;
}

int main()
{
    return 0;
}