#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int dir = 0;
    int row = 0, col = 0;
    vector<int> res;

    while (row < rows && col < cols)
    {
        if (dir == 0) // right
        {
            for (int i = col; i < cols; i++)
                res.push_back(matrix[row][i]);

            row++;
        }
        else if (dir == 1) // down
        {
            for (int i = row; i < rows; i++)
                res.push_back(matrix[i][cols - 1]);

            cols--;
        }
        else if (dir == 2) // left
        {
            for (int i = cols - 1; i >= col; i--)
                res.push_back(matrix[rows - 1][i]);

            rows--;
        }
        else if (dir == 3) // up
        {
            for (int i = rows - 1; i >= row; i--)
                res.push_back(matrix[i][col]);

            col++;
        }

        dir = (dir + 1) % 4;
    }

    return res;
}