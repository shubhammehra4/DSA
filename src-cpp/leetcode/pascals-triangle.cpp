#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res(numRows);

    for (int row = 0; row < numRows; row++)
    {
        res[row].resize(row + 1);

        res[row][0] = 1;
        res[row][row] = 1;

        for (int j = 1; j < row; j++)
            res[row][j] = res[row - 1][j - 1] + res[row - 1][j];
    }

    return res;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;

    for (int row = 0; row < numRows; row++)
    {
        vector<int> temp(row + 1, 1);

        for (int col = 1; col < row; col++)
            temp[col] = res[row - 1][col] + res[row - 1][col - 1];

        res.push_back(temp);
    }
    return res;
}