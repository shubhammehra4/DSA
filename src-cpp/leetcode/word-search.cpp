#include <bits/stdc++.h>
using namespace std;

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();

    vector<short> directions{-1, 0, 1, 0, -1};

    function<bool(int, int, int)> explore =
        [&board, &word, &directions, &explore](int row, int col, int wordIdx) -> bool
    {
        if (wordIdx == word.size() - 1)
            return true;

        char tmp = board[row][col];
        board[row][col] = '-1';

        for (int d = 0; d < 4; d++)
        {
            int r = row + directions[d];
            int c = col + directions[d + 1];

            if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] == word[wordIdx + 1])
            {
                if (explore(r, c, wordIdx + 1))
                    return true;
            }
        }

        board[row][col] = tmp;
        return false;
    };

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (board[r][c] == word[0] && explore(r, c, 0))
                return true;
        }
    }

    return false;
}

// alter
bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();

    function<bool(int, int, int)> explore =
        [&board, &word, &explore](int row, int col, int wordIdx) -> bool
    {
        if (wordIdx == word.size())
            return true;

        if (row < 0 || col < 0 || row > board.size() - 1 || col > board[0].size() - 1)
            return false;

        if (board[row][col] != word[wordIdx])
            return false;

        board[row][col] = '*';
        bool furtherSearch = explore(row + 1, col, wordIdx + 1) || explore(row - 1, col, wordIdx + 1) || explore(row, col - 1, wordIdx + 1) || explore(row, col + 1, wordIdx + 1);

        board[row][col] = word[wordIdx];
        return furtherSearch;
    };

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (explore(r, c, 0))
                return true;
        }
    }

    return false;
}