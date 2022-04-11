#include <bits/stdc++.h>
using namespace std;

// space-optimised
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    bool firstRow = false;
    bool firstCol = false;
    for (int col = 0; col < n; col++) // check the first row
        if (matrix[0][col] == 0)
        {
            firstRow = true;
            break;
        }

    for (int row = 0; row < m; row++) // check the first column
        if (matrix[row][0] == 0)
        {
            firstCol = true;
            break;
        }

    for (int row = 1; row < m; row++) // check except the first row and column
    {
        for (int col = 1; col < n; col++)
        {
            if (matrix[row][col] == 0)
            {
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }

    for (int row = 1; row < m; row++) // process except the first row and column
    {
        for (int col = 1; col < n; col++)
        {
            if (matrix[row][0] == 0 || matrix[0][col] == 0)
                matrix[row][col] = 0;
        }
    }
    if (firstRow)
    {
        for (int col = 0; col < n; col++)
            matrix[0][col] = 0;
    }

    if (firstCol)
    {
        for (int row = 0; row < m; row++)
            matrix[row][0] = 0;
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    set<int> rows;
    set<int> cols;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (rows.count(i) || cols.count(j))
                matrix[i][j] = 0;
}