#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> res(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    for (auto i = 0; i < m; ++i)
    {
        for (auto j = 0; j < mat[0].size(); ++j)
        {
            if (mat[i][j] == 0)
            {
                res[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vector<int> dir = {-1, 0, 1, 0, -1};

    while (!q.empty())
    {
        auto curr = q.front();
        int x = curr.first, y = curr.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = x + dir[i];
            int c = y + dir[i + 1];
            if (r >= 0 && r < m && c >= 0 && c < n && res[r][c] > res[x][y])
            {
                res[r][c] = res[x][y] + 1;
                q.push({r, c});
            }
        }
    }

    return res;
}

int main()
{
    return 0;
}