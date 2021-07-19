#include <bits/stdc++.h>
using namespace std;

bool win(vector<vector<int>> s)
{
    for (int i = 0; i < 3; i++)
    {
        if (s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][1] != 0)
            return true;

        if (s[0][i] == s[1][i] && s[1][i] == s[2][i] && s[1][i] != 0)
            return true;
    }

    if (s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[1][1] != 0)
        return true;

    if (s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[1][1] != 0)
        return true;

    return false;
}

string tictactoe(vector<vector<int>> &moves)
{
    vector<vector<int>> grid(3, vector<int>(3, 0));

    bool chk = true;
    for (auto i : moves)
    {
        grid[i[0]][i[1]] = (chk) ? 1 : -1;
        if (win(grid))
            return (chk) ? "A" : "B";

        chk = !chk;
    }

    if (moves.size() == 9)
        return "Draw";

    return "Pending";
}

int main()
{
    return 0;
}