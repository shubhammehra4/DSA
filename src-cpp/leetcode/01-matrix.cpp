#include <bits/stdc++.h>
using namespace std;

// dp
vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX - 100000));

    // First pass: check for left and top
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (matrix[r][c] == 0)
                dist[r][c] = 0;
            else
            {
                if (r > 0)
                    dist[r][c] = min(dist[r][c], dist[r - 1][c] + 1);
                if (c > 0)
                    dist[r][c] = min(dist[r][c], dist[r][c - 1] + 1);
            }
        }
    }

    // Second pass: check for bottom and right
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i < m - 1)
                dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            if (j < n - 1)
                dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
        }
    }

    return dist;
}

// bfs
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    const int m = mat.size();
    const int n = mat[0].size();
    vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    for (auto i = 0; i < m; ++i)
    {
        for (auto j = 0; j < mat[0].size(); ++j)
        {
            if (mat[i][j] == 0)
            {
                distance[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vector<int> directions = {-1, 0, 1, 0, -1};
    auto isValidCoordinates = [&m, &n](int r, int c) -> bool
    {
        return r >= 0 && r < m && c >= 0 && c < n;
    };

    while (!q.empty())
    {
        auto corrdinates = q.front();
        q.pop();
        int x = corrdinates.first;
        int y = corrdinates.second;

        for (int i = 0; i < 4; i++)
        {
            int r = x + directions[i];
            int c = y + directions[i + 1];
            if (isValidCoordinates(r, c) && distance[r][c] > distance[x][y] + 1)
            {
                distance[r][c] = distance[x][y] + 1;
                q.push({r, c});
            }
        }
    }

    return distance;
}

// naive brute-force tle
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    const int m = mat.size();
    const int n = mat[0].size();

    vector<vector<int>> res(m, vector<int>(n));

    function<int(int, int)> bfs = [&mat, &m, &n](int r, int c) -> int
    {
        queue<pair<int, int>> q;
        vector<vector<bool>> v(m, vector<bool>(n, false));

        q.push({r, c});

        int distance = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto cord = q.front();
                auto x = cord.first;
                auto y = cord.second;
                q.pop();
                v[cord.first][cord.second] = true;

                if (mat[x][y] == 0)
                    return distance + 1;
                else
                {
                    if (x > 0 && !v[x - 1][y])
                        q.push({x - 1, y});
                    if (y > 0 && !v[x][y - 1])
                        q.push({x, y - 1});

                    if (x < m - 1 && !v[x + 1][y])
                        q.push({x + 1, y});
                    if (y < n - 1 && !v[x][y + 1])
                        q.push({x, y + 1});
                }
            }
            distance++;
        }

        return INT_MAX;
    };

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (mat[r][c] == 0)
                res[r][c] = 0;
            else
                res[r][c] = bfs(r, c);
        }
    }

    return res;
}