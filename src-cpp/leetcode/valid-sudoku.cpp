#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    vector<vector<bool>> rowCheck(9, vector<bool>(9, false));
    vector<vector<bool>> colCheck(9, vector<bool>(9, false));
    vector<vector<bool>> blockCheck(9, vector<bool>(9, false)); // 3*3 grid

    auto getBlockId = [](int r, int c) -> int
    {
        return (r / 3) * 3 + c / 3;
    };

    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board[row].size(); col++)
            if (board[row][col] != '.')
            {
                int num = (board[row][col] - '0') - 1;
                int blockId = getBlockId(row, col);

                if (rowCheck[row][num] || colCheck[col][num] || blockCheck[blockId][num])
                    return false;

                rowCheck[row][num] = true;
                colCheck[col][num] = true;
                blockCheck[blockId][num] = true;
            }
    }

    return true;
}

// alter
bool isValidSudoku(vector<vector<char>> &board)
{
    vector<vector<bool>> rowCheck(9, vector<bool>(9, false));
    vector<vector<bool>> colCheck(9, vector<bool>(9, false));
    vector<vector<vector<bool>>> blockCheck(3, vector<vector<bool>>(3, vector<bool>(9, false)));

    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board[row].size(); col++)
            if (board[row][col] != '.')
            {
                int num = (board[row][col] - '0') - 1;

                if (rowCheck[row][num] || colCheck[col][num] || blockCheck[row / 3][col / 3][num])
                    return false;

                rowCheck[row][num] = true;
                colCheck[col][num] = true;
                blockCheck[row / 3][col / 3][num] = true;
            }
    }

    return true;
}