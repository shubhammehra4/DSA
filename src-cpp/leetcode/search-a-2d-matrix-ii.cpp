#include <bits/stdc++.h>
using namespace std;

// search from top-right
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = m ? matrix[0].size() : 0;

    int row = 0, col = n - 1; // top right index

    while (row < m && col >= 0)
    {
        if (matrix[row][col] == target)
            return true;

        if (matrix[row][col] > target)
            col--;
        else
            row++;
    }

    return false;
}

// brute-force (less operations)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (auto &row : matrix)
    {
        if (row.front() > target || row.back() < target)
            continue;

        if (binary_search(begin(row), end(row), target))
            return true;
    }

    return false;
}

// brute-force
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (auto &row : matrix)
    {
        if (binary_search(begin(row), end(row), target))
            return true;
    }

    return false;
}